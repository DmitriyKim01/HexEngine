#pragma once

#include <graphics/renderer/Renderer.h>
#include <graphics/window/Window.h>
#include <graphics/renderer/opengl/OpenGLShader.h>
#include <graphics/renderer/opengl/OpenGLRectangleBatch.h>
#include <graphics/renderer/opengl/OpenGLTriangleBatch.h>

class OpenGLRenderer : public Renderer
{
private:
	Window* m_window = nullptr;
	Color m_clearColor;
	OpenGLShader m_shader;
	OpenGLRectangleBatch m_rectangleBatch;
	OpenGLTriangleBatch m_triangleBatch;
public:
	OpenGLRenderer(Window& window, const Color& clearColor);
	~OpenGLRenderer() override;

	void initialize(Window& window) override;
	void shutdown() override;

	void beginFrame() override;
	void endFrame() override;

	void clear() override;
	void setClearColor(const Color& color) override;

	void onResize(int width, int height) override;

	void draw(const Rectangle& rectangle) override;
	void draw(const Triangle& triangle);
};