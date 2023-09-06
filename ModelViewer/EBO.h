#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <vector>
#include<glad/glad.h>

class EBO
{/*
 Elements Buffer Object
 A buffer that stores indices that OpenGL uses to decide what vertices of a shape to draw.
 The EBO specifies the order in which the vertices should be drawn in.
 This is useful for drawing complex models, without an EBO the user would have to define 
 all the vertices of each triangle, meaning many vertices that should be unique would be duplicated.
 With an EBO, the user only needs to store the unique vertices that are needed and then specify 
 their order.
 */
public:
	// ID reference of Elements Buffer Object
	GLuint ID;
	// Constructor that generates a Elements Buffer Object and links it to indices
	EBO(std::vector<GLuint>& indices);

	// Binds the EBO
	void Bind();
	// Unbinds the EBO
	void Unbind();
	// Deletes the EBO
	void Delete();
};

#endif