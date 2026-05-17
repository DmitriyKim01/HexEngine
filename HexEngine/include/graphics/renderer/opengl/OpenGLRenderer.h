#pragma once

#include <graphics/renderer/Renderer.h>
#include <graphics/window/Window.h>
#include <graphics/renderer/opengl/Shader.h>

class OpenGLRenderer : public Renderer
{
private:
	Window* m_Window = nullptr;
	unsigned int m_ShaderProgram = 0;
	Color m_ClearColor;

	Shader m_Shader;
	unsigned int m_RectangleVAO = 0;
	unsigned int m_RectangleVBO = 0;

	void initRectangleBuffers();
	void destroyRectangleBuffers();
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
};