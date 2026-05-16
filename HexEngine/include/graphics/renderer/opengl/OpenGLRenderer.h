#pragma once

#include <graphics/renderer/Renderer.h>
#include <graphics/window/Window.h>

class OpenGLRenderer : public Renderer
{
private:
	Color m_ClearColor;
public:
	OpenGLRenderer();
	OpenGLRenderer(Color clearColor);
	OpenGLRenderer(float red, float green, float blue, float alpha = 1.0f);

	void beginFrame() override;
	void endFrame() override;

	void setClearColor(Color color) override;

	void drawRectangle(const Rectangle& rectangle) override;
};