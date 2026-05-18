#include <graphics/window/Window.h>
#include <graphics/renderer/opengl/OpenGLShader.h>
#include <graphics/window/GLFWindow.h>
#include <graphics/shapes/Color.h>
#include <graphics/shapes/2d/Rectangle.h>
#include <graphics/renderer/Renderer.h>
#include <graphics/renderer/opengl/OpenGLRenderer.h>

const unsigned int SCREEN_WIDTH = 1920;
const unsigned int SCREEN_HEIGHT = 1080;

int main()
{
	Rectangle rect(Position(0, 0), 200, 200, Color::Red);
	Rectangle rect2(400, 300, 150, 150, Color::Green);
	Rectangle rect3(600, 200, 50, 200, Color::Blue);

	Window* window = new GLFWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HexEngine");
	Renderer* renderer = new OpenGLRenderer(*window, Color::White);

	while (!window->shouldClose())
	{
		renderer->beginFrame();

		renderer->draw(rect);
		renderer->draw(rect2);
		renderer->draw(rect3);

		renderer->endFrame();

		window->update();
	}

	delete renderer;
	delete window;
	return 0;
}