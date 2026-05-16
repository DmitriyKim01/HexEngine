#pragma once

#include <graphics/shapes/Color.h>

class Window {
public:
	virtual ~Window() = default;

	virtual void update() = 0;
	virtual bool shouldClose() = 0;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
};

