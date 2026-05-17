#include <graphics/renderer/opengl/OpenGLRenderer.h>
#include <graphics/shapes/Position.h>

#include <glad/glad.h>

#include <iostream>
#include <stdexcept>
#include <array>

OpenGLRenderer::OpenGLRenderer(Window& window, const Color& clearColor)
	: m_ClearColor(clearColor), m_Shader("assets/opengl/shaders/base.vert", "assets/opengl/shaders/base.frag")
{
	initialize(window);
	initRectangleBuffers();
}

OpenGLRenderer::~OpenGLRenderer()
{
	shutdown();
}

void OpenGLRenderer::initRectangleBuffers()
{
	glGenVertexArrays(1, &m_RectangleVAO);
	glGenBuffers(1, &m_RectangleVBO);

	glBindVertexArray(m_RectangleVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_RectangleVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 18, nullptr, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Position),
		reinterpret_cast<void*>(0)
	);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

void OpenGLRenderer::destroyRectangleBuffers()
{
	if (m_RectangleVBO != 0)
	{
		glDeleteBuffers(1, &m_RectangleVBO);
		m_RectangleVBO = 0;
	}

	if (m_RectangleVAO != 0)
	{
		glDeleteVertexArrays(1, &m_RectangleVAO);
		m_RectangleVAO = 0;
	}
}

void OpenGLRenderer::initialize(Window& window)
{
	m_Window = &window;
	glViewport(0, 0, window.getWidth(), window.getHeight());
}

void OpenGLRenderer::shutdown()
{
	destroyRectangleBuffers();
}

void OpenGLRenderer::beginFrame()
{
	float red = m_ClearColor.getRed();
	float green = m_ClearColor.getGreen();
	float blue = m_ClearColor.getBlue();
	float alpha = m_ClearColor.getAlpha();

	m_Shader.use();
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
	// Normalize coordinates to OpenGL's NDC (-1.0f to 1.0f)
	float left = (rectangle.position.x / m_Window->getWidth()) * 2.0f - 1.0f;
	float right = ((rectangle.position.x + rectangle.getWidth()) / m_Window->getWidth()) * 2.0f - 1.0f;

	float top = 1.0f - (rectangle.position.y / m_Window->getHeight()) * 2.0f;
	float bottom = 1.0f - ((rectangle.position.y + rectangle.getHeight()) / m_Window->getHeight()) * 2.0f;

	float z = (rectangle.position.z - 0.0f) / (100.0f - 0.0f) * 2.0f - 1.0f;

	std::array<float, 18> rectangleVertices = {
		// First Triangle
		left,  top,		z,
		right, top,		z,
		right, bottom,	z,
		// Second Triangle
		left,  top,		z,
		right, bottom,	z,
		left,  bottom,  z,
	};

	unsigned int indices[] = {  // note that we start from 0!
	  0, 1, 3,  // first Triangle
	  1, 2, 3   // second Triangle
	};

	glBindVertexArray(m_RectangleVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_RectangleVBO);

	glBufferSubData(
		GL_ARRAY_BUFFER,
		0,
		sizeof(rectangleVertices),
		rectangleVertices.data()
	);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}