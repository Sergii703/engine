//#include <GLFW/glfw3.h>
//#include <iostream>

#include "window.h"
int main(){

	using namespace sparky;
	using namespace graphics;
	using namespace std;

	Window window("Sparky", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		glClear(GL_COLOR_BUFFER_BIT);
	
		window.clear();
		
		if (window.isKeyPressed(GLFW_KEY_A)) {
			std::cout << "PRESSED" << std::endl;
		}

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			std::cout << "PRESSED" << std::endl;
		}

		double x, y;
		Window::getMousePosition(x, y);
		std::cout << x << ", "<< y << std::endl;
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}
	return 0;
}