

#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

class VAO
/*
Vertex Array Object, stores pointers to one or more VBOs and tells OpenGL how to interpret them.
VAOs exist in order to quickly be able to switch between different VBOs.
*/
{
public:
	// ID reference for the Vertex Array Object
	GLuint ID;
	VAO();

	// Links a VBO to the VAO using a certain layout
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents,
		GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};
#endif