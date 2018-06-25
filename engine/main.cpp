//#include <GLFW/glfw3.h>
#include "utils/fileUtils.h"
#include "graphics/window.h"
#include "graphics/shader.h"
#include "maths/maths.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexBuffer.h"
#include "graphics/buffers/vertexArray.h"

#include "graphics/renderable2D.h"
#include "graphics/renderer2D.h"
#include "graphics/simple2Drenderer.h"

int main(){

	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky", 800, 600);
	
	mat4 ortho = mat4::perspective(0.0f, 16.0f, 0.0f, 9.0f);
	
	Shader shader("shaders/basic.vert", "shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	
	Renderable2D sprite(maths::vec3(0, 0, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), shader);
	Simple2DRenderer renderer;
	
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));

		renderer.submit(&sprite);
		renderer.flush();

		window.update();
	}
	return 0;
}