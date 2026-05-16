#pragma once

#include <graphics/renderer/Renderer.h>
#include <graphics/window/Window.h>

class OpenGLRenderer : public Renderer
{
private:
	Window* m_Window = nullptr;
	Color m_ClearColor;
public:
	OpenGLRenderer(Window& window, const Color& clearColor);

	void initialize(Window& window) override;
	void shutdown() override;

	void beginFrame() override;
	void endFrame() override;

	void clear() override;
	void setClearColor(const Color& color) override;

	void onResize(int width, int height) override;

	void draw(const Rectangle& rectangle) override;
};