#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "shaderClass.h"

class Camera {
public:
	//The camera's main vectors
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	//Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;

	//Width and height of the window
	int width;
	int height;
	//Adjust camera speed and sensitivity when looking around
	float speed = 0.01f;
	float sensitivity = 30.0f;

	Camera(int width, int height, glm::vec3 position);

	//Updates and exports the camera matrix to the vertex shader

	void updateMatrix(float FOVdeg, float nearplane, float farPlane);
	void Matrix(Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);
};


#endif 
