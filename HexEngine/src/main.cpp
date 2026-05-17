#include <graphics/window/Window.h>
#include <graphics/renderer/opengl/Shader.h>
#include <graphics/window/GLFWindow.h>
#include <graphics/shapes/Color.h>
#include <graphics/shapes/2d/Rectangle.h>
#include <graphics/renderer/Renderer.h>
#include <graphics/renderer/opengl/OpenGLRenderer.h>

#include <iostream>

const unsigned int SCREEN_WIDTH = 1920;
const unsigned int SCREEN_HEIGHT = 1080;

int main()
{
	Rectangle rect(Position(100.0f, 150.0f), 200.0f, 100.0f, Color::Red);
	Rectangle rect2(400.0f, 300.0f, 150.0f, 150.0f, Color::Green);
	Rectangle rect3(600.0f, 200.0f, 50.0f, 200.0f, Color::Blue);

	Window* window = new GLFWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HexEngine");
	Renderer* renderer = new OpenGLRenderer(*window, Color::White);
	Shader ourShader("assets/opengl/shaders/base.vert", "assets/opengl/shaders/base.frag");

	float vertices[] = {
		// positions         // colors
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	// glBindVertexArray(0);


	while (!window->shouldClose())
	{
		renderer->beginFrame();

		ourShader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//renderer->draw(rect);

		renderer->endFrame();
		window->swapBuffers();
		window->pollEvents();
	}
	
	renderer->shutdown();
	window->shutdown();

	delete renderer;
	delete window;
	return 0;
}