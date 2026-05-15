#include <graphics/opengl/IWindow.h>
#include <graphics/opengl/OpenGLWindow.h>
#include <graphics/shapes/Color.h>
#include <iostream>

const unsigned int SCREEN_WIDTH = 1920;
const unsigned int SCREEN_HEIGHT = 1080;

int main() {
    
	IWindow* window = new OpenGLWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HexEngine");
    while (!window->shouldClose())
    {
        window->setBackgroundColor(Color::White);
		window->update();
    }
    delete window;
	return 0;
}