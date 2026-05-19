#include <graphics/renderer/opengl/OpenGLRenderer.h>
#include <graphics/shapes/Position.h>
#include <graphics/shapes/Color.h>

#include <glad/glad.h>

#include <iostream>
#include <stdexcept>
#include <array>

OpenGLRenderer::OpenGLRenderer(Window& window, const Color& clearColor)
	:	m_clearColor(clearColor), 
		m_shader("assets/opengl/shaders/base.vert", "assets/opengl/shaders/base.frag"),
		m_rectangleBatch()
{
	initialize(window);
}

OpenGLRenderer::~OpenGLRenderer()
{
	shutdown();
}

void OpenGLRenderer::initialize(Window& window)
{
	m_window = &window;
	glViewport(0, 0, window.getWidth(), window.getHeight());
}

void OpenGLRenderer::shutdown()
{
}

void OpenGLRenderer::beginFrame()
{
	float red = m_clearColor.getRed();
	float green = m_clearColor.getGreen();
	float blue = m_clearColor.getBlue();
	float alpha = m_clearColor.getAlpha();

	m_shader.use();
	m_shader.setVec2("u_Resolution",
					 static_cast<float>(m_window->getWidth()),
					 static_cast<float>(m_window->getHeight()));

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
	m_clearColor = color;
}

void OpenGLRenderer::onResize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void OpenGLRenderer::draw(const Rectangle& rectangle)
{
	m_rectangleBatch.draw(rectangle);
}