#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <graphics/window/GLFWindow.h>

#include <stdexcept>
#include <iostream>

int GLFWindow::validateDimension(int value, const std::string& name)
{
	if (value <= 0)
		throw std::invalid_argument(name + " must be a positive integer.");

	return value;
}

// Constructors ==========================================

GLFWindow::GLFWindow()
	: m_Width(Defaults::WIDTH), m_Height(Defaults::HEIGHT), m_Title(Defaults::TITLE)
{
	init();
}

GLFWindow::GLFWindow(int width, int height)
	: m_Width(validateDimension(width, "width")),
	m_Height(validateDimension(height, "height")),
	m_Title(Defaults::TITLE)
{
	init();
}

GLFWindow::GLFWindow(int width, int height, const std::string& title)
	: m_Width(validateDimension(width, "width")),
	m_Height(validateDimension(height, "height")),
	m_Title(title)
{
	init();
}

void GLFWindow::shutdown()
{
	if (m_Window)
	{
		glfwDestroyWindow(m_Window);
		m_Window = nullptr;
	}
	glfwTerminate();
}

GLFWindow::~GLFWindow()
{
	shutdown();
}

// IWindow Interface Implementation =====================

void GLFWindow::init()
{
	if (!glfwInit())
		throw std::runtime_error("OpenGLWindow: glfwInit() failed");

	setGLFWHints();

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

	if (!m_Window)
	{
		glfwTerminate();
		throw std::runtime_error("OpenGLWindow: glfwCreateWindow() failed");
	}
	glfwMakeContextCurrent(m_Window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error("OpenGLWindow: gladLoadGLLoader() failed");

	// Keep stored dimensions in sync if GLFW adjusted them
	glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
	glViewport(0, 0, m_Width, m_Height);
}

void GLFWindow::pollEvents()
{
	glfwPollEvents();
}

void GLFWindow::swapBuffers()
{
	glfwSwapBuffers(m_Window);
}

bool GLFWindow::shouldClose()
{
	return glfwWindowShouldClose(m_Window);
}

int GLFWindow::getWidth()  const { return m_Width; }
int GLFWindow::getHeight() const { return m_Height; }

void GLFWindow::setGLFWHints()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Defaults::GL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Defaults::GL_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // required on macOS
#endif
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
}