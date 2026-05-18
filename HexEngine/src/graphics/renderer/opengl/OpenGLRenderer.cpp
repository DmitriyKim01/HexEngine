#include <graphics/renderer/opengl/OpenGLRenderer.h>
#include <graphics/shapes/Position.h>
#include <graphics/shapes/Color.h>

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
	glGenBuffers(1, &m_RectangleEBO);

	glBindVertexArray(m_RectangleVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_RectangleVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, nullptr, GL_DYNAMIC_DRAW);

	static constexpr unsigned int indices[] = {
	0, 1, 2,   // first triangle  (top-left, top-right, bottom-right)
	0, 2, 3    // second triangle (top-left, bottom-right, bottom-left)
	};

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RectangleEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		6 * sizeof(float),
		(void*)0
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		6 * sizeof(float),
		(void*)(3 * sizeof(float))
	);
	glEnableVertexAttribArray(1);

	//glBindVertexArray(0);
}

void OpenGLRenderer::destroyRectangleBuffers()
{
	if (m_RectangleEBO != 0)
	{
		glDeleteBuffers(1, &m_RectangleEBO);
		m_RectangleEBO = 0;
	}
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
	m_Shader.setVec2("u_Resolution",
					 static_cast<float>(m_Window->getWidth()),
					 static_cast<float>(m_Window->getHeight()));

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
	std::array<float, 24> rectangleVertices = rectangle.getVertices();

	glBindVertexArray(m_RectangleVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_RectangleVBO);
	glBufferSubData(
		GL_ARRAY_BUFFER,
		0,
		sizeof(rectangleVertices),
		rectangleVertices.data()
	);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}