#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "AppData.h"

int AppData::Setup()
{
	open = true;
	//example tri
	float vertices[] = {
		0.0f, 0.5f, // Vertex 1 (X, Y)
		0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};
	//Init functions
	if (!glfwInit())
	{
		printf("Could not Initalize \n Closing...");
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	if ((window = glfwCreateWindow(800, 600, "TeapotExplsoion", nullptr, nullptr)) == NULL)
	{
		printf("Could not create window \n Closing...");
		return -1;
	}
	else
	{
		glfwMakeContextCurrent(window);
	}
	//glew stuff
	GLenum glew_status;

	glewExperimental = GL_TRUE;
	glew_status = glewInit();
	
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);

	GLuint vbo;
	glGenBuffers(1, &vbo); // Generate 1 buffer

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	return 0;
}

int AppData::Run()
{
	//Loop
	do
	{
		Input();
		Draw();
	} while (open);
	return 0;

}

int AppData::Input()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
			open = false;
		}
	}
	return 0;
}

int AppData::Draw()
{

	return 0;
}

int AppData::Shutdown()
{
	glfwTerminate();
	return 0;
}