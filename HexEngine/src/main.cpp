#include <graphics/window/Window.h>
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
	Renderer* renderer = new OpenGLRenderer(Color(0.1f, 0.1f, 0.1f));


	while (!window->shouldClose())
	{
		window->update();
	}
	delete window;
	return 0;
}