#include <graphics/renderer/opengl/OpenGLRenderer.h>

#include <glad/glad.h>

#include <stdexcept>

OpenGLRenderer::OpenGLRenderer() : m_ClearColor(0, 0, 0, 1.0f)
{}

OpenGLRenderer::OpenGLRenderer(Color clearColor) : m_ClearColor(clearColor)
{}

OpenGLRenderer::OpenGLRenderer(float red, float green, float blue, float alpha) : m_ClearColor(red, green, blue, alpha)
{}

void OpenGLRenderer::beginFrame()
{
	float red = m_ClearColor.getRed();
	float green = m_ClearColor.getGreen();
	float blue = m_ClearColor.getBlue();
	float alpha = m_ClearColor.getAlpha();

	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::endFrame()
{
	throw std::logic_error("Renderer::render() is not implemented.");
}

void OpenGLRenderer::setClearColor(Color color)
{
	m_ClearColor = color;
}

void OpenGLRenderer::drawRectangle(const Rectangle& rectangle)
{
	throw std::logic_error("Renderer::drawRectangle() is not implemented.");
}