#ifndef __APP_H_
#define __APP_H_

class AppData
{
	bool open;
	GLFWwindow* window;
	GLuint vbo;


	int Input();
	int Update();
	int Draw();

public:
	int Setup();
	int Run();
	int Shutdown();

};

//extern AppData app;

#endif //__APP_H_
