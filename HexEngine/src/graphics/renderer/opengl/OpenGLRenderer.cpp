#include <graphics/renderer/opengl/OpenGLRenderer.h>

#include <glad/glad.h>

#include <stdexcept>

OpenGLRenderer::OpenGLRenderer(Window& window, const Color& clearColor)
	: m_ClearColor(clearColor)
{
	initialize(window);
}

void OpenGLRenderer::initialize(Window& window)
{
	m_Window = &window;
	glViewport(0, 0, window.getWidth(), window.getHeight());
}

void OpenGLRenderer::shutdown()
{

}

void OpenGLRenderer::beginFrame()
{
	float red = m_ClearColor.getRed();
	float green = m_ClearColor.getGreen();
	float blue = m_ClearColor.getBlue();
	float alpha = m_ClearColor.getAlpha();

	glClearColor(red, green, blue, alpha);
	clear();
}

void OpenGLRenderer::endFrame()
{

}

void OpenGLRenderer::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::setClearColor(const Color& color)
{
	m_ClearColor = color;
}

void OpenGLRenderer::onResize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void OpenGLRenderer::draw(const Rectangle& rectangle)
{
	throw std::logic_error("Renderer::drawRectangle() is not implemented.");
}