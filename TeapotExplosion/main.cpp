#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include "AppData.h"



AppData app;

int main(int argv, char *args[])
{
	if (app.Setup() < 0)
		return -1;
	app.Run();
	app.Shutdown();
	
	return 0;
}