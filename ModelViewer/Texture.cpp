#include "Texture.h"

Texture::Texture(const char* image, const char* texType, GLuint slot)
{
	//Assigns the type of the texture to the texture object
	type = texType;

	//Stores the width, height and number of colour channels of the image
	int widthImg, heightImg, numColCh;
	//by default stb loads images from the top-left to lower-right corner,
	//which displays images upside-down when using OpenGL. This function flips the image.
	stbi_set_flip_vertically_on_load(true);
	//Reads the image from a file and stores it in byte format
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	//Generates an OpenGL texture object
	glGenTextures(1, &ID);
	//Assigns the texture to a Texture Unit
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;
	glBindTexture(GL_TEXTURE_2D, ID);

	//Configures the type of algorithm used for resizing the image
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//Settings for how the repeats itself
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if (numColCh == 4) {
		glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	}
	else if (numColCh == 3) {
		glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
	}
	else if (numColCh == 2) {
		glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RED, GL_UNSIGNED_BYTE, bytes);
	}
	else {
		throw std::invalid_argument("Automatic texture type recognition failed");
	}

	glGenerateMipmap(GL_TEXTURE_2D);

	//Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(bytes);
	//Unbinds the OpenGL texture object so that it cannot be accidentally modified
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	//Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	//Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}
