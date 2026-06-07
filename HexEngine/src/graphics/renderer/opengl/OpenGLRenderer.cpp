#include <graphics/renderer/opengl/OpenGLRenderer.h>
#include <graphics/shapes/Position.h>
#include <graphics/shapes/Color.h>
#include <graphics/shapes/3d/Cube.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <stdexcept>
#include <array>

OpenGLRenderer::OpenGLRenderer(Window& window, const Color& clearColor)
	:	m_clearColor(clearColor), 
		m_shader("assets/opengl/shaders/base.vert", "assets/opengl/shaders/base.frag"),
		m_rectangleBatch(),
		m_triangleBatch(),
		m_cubeBatch()
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
	glEnable(GL_DEPTH_TEST);
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

	//// create transformations
	//glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	//glm::mat4 view = glm::mat4(1.0f);
	//glm::mat4 projection = glm::mat4(1.0f);
	//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	//projection = glm::perspective(glm::radians(45.0f), (float)1920 / (float)1080, 0.1f, 100.0f);
	//// retrieve the matrix uniform locations
	//unsigned int modelLoc = glGetUniformLocation(m_shader.ID, "model");
	//unsigned int viewLoc = glGetUniformLocation(m_shader.ID, "view");
	//// pass them to the shaders (3 different ways)
	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	//// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	//m_shader.setMat4("projection", projection);


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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

void OpenGLRenderer::draw(const Triangle& triangle)
{
	m_triangleBatch.draw(triangle);
}

void OpenGLRenderer::draw(const Cube& cube)
{
	m_cubeBatch.draw(cube);
}