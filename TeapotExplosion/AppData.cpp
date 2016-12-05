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

	glGenBuffers(1, &vbo); // Generate 1 buffer

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	//vertex shader
	const GLchar* vertexSource =
		"#version 150 core\n"
		"in vec2 position;"
		"in vec3 color;"
		"out vec3 Color;"
		"void main() {"
		"   Color = color;"
		"   gl_Position = vec4(position, 0.0, 1.0);"
		"}";
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE){
		char shaderCompileoutput[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, shaderCompileoutput);
	}
	//frag shader
	const GLchar* fragmentSource =
		"#version 150 core\n"
		"out vec4 outColor;"
		"uniform vec3 triangleColor;"
		"void main()"
		"{"
		"    outColor = vec4(triangleColor, 1.0);"
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	//shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");

	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(posAttrib);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


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