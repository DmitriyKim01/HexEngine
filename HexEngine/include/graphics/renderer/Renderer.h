#pragma once

#include <graphics/shapes/Color.h>
#include <graphics/shapes/2d/Rectangle.h>
#include <graphics/window/Window.h>

class Renderer {
public:
	virtual ~Renderer() = default;

	virtual void initialize(Window& window) = 0;
	virtual void shutdown() = 0;

	virtual void beginFrame() = 0;
	virtual void endFrame() = 0;

	virtual void clear() = 0;
	virtual void setClearColor(const Color& color) = 0;

	virtual void onResize(int width, int height) = 0;

	virtual void draw(const Rectangle& rectangle) = 0;
};