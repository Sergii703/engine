//#include <GLFW/glfw3.h>
//#include <iostream>

#include "window.h"
#include "maths/maths.h"

int main(){

	using namespace sparky;
	using namespace graphics;
	using namespace maths;
	//using namespace std;

	Window window("Sparky", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);

	vec4 c = a * b;

	mat4 position = mat4::translation(vec3(2, 3, 4));


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
		window.getMousePosition(x, y);
		std::cout << x << ", "<< y << std::endl;

		std::cout << a << std::endl;
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