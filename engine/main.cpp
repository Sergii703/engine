//#include <GLFW/glfw3.h>
//#include <iostream>

#include "window.h"
int main(){

	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();
#if 0
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}
	//system("PAUSE");

	return 0;
}