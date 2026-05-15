#pragma once

class IWindow {
public:
	virtual ~IWindow() = default;

	virtual void update() = 0;
	virtual bool shouldClose() = 0;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
};

