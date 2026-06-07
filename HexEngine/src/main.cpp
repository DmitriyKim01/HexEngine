#include <graphics/window/Window.h>
#include <graphics/renderer/opengl/OpenGLShader.h>
#include <graphics/window/GLFWindow.h>
#include <graphics/shapes/Color.h>
#include <graphics/shapes/2d/Rectangle.h>
#include <graphics/renderer/Renderer.h>
#include <graphics/renderer/opengl/OpenGLRenderer.h>
#include <graphics/renderer/opengl/OpenGLTriangleBatch.h>
#include <graphics/shapes/3d/Cube.h>

const unsigned int SCREEN_WIDTH = 1920;
const unsigned int SCREEN_HEIGHT = 1080;

int main()
{
	Rectangle rect(Position(0, 0), 200, 200, Color::Red);
	Triangle tri(Position(400, 400), 200, 200, Color::Yellow);
	Cube cube(Position(400, 400, 0), 200, 200, 200, Color::Cyan);

	Window* window = new GLFWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HexEngine");
	Renderer* renderer = new OpenGLRenderer(*window, Color::White);

	while (!window->shouldClose())
	{
		renderer->beginFrame();

		renderer->draw(rect);
		renderer->draw(tri);
		renderer->draw(cube);

		renderer->endFrame();

		window->update();
	}

	delete renderer;
	delete window;
	return 0;
}