#pragma once

#include <graphics/shapes/Color.h>

class IWindow {
public:
	virtual ~IWindow() = default;

	virtual void update() = 0;
	virtual bool shouldClose() = 0;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

	virtual void setBackgroundColor(float red, float green, float blue, float alpha) = 0;
	virtual void setBackgroundColor(Color color) = 0;
};

