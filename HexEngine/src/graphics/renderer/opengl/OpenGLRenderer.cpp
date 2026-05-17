#include <graphics/renderer/opengl/OpenGLRenderer.h>

#include <glad/glad.h>

#include <iostream>
#include <stdexcept>
#include <array>

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

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, rectangleVertices.size() * sizeof(float), rectangleVertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// In a loop
	// draw our first triangle
	glUseProgram(m_ShaderProgram);
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}