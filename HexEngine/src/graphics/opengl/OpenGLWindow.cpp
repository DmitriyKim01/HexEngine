#include <glad/glad.h>
#include <graphics/opengl/OpenGLWindow.h>
#include <stdexcept>
#include <iostream>

int OpenGLWindow::validateDimension(int value, const std::string& name) 
{
	if (value <= 0) {
		throw std::invalid_argument(name + " must be a positive integer.");
	}
	return value;
}

// Constructors ==========================================

OpenGLWindow::OpenGLWindow()
	: m_Width(Defaults::WIDTH), m_Height(Defaults::HEIGHT), m_Title(Defaults::TITLE) {
	init();
}

OpenGLWindow::OpenGLWindow(int width, int height)
	:	m_Width(validateDimension(width, "width")), 
		m_Height(validateDimension(height, "height")), 
		m_Title(Defaults::TITLE) {
	init();
}

OpenGLWindow::OpenGLWindow(int width, int height, const std::string& title)
	:	m_Width(validateDimension(width, "width")), 
		m_Height(validateDimension(height, "height")), 
		m_Title(title) {
	init();
}

OpenGLWindow::~OpenGLWindow() {
	if (m_Window) {
		glfwDestroyWindow(m_Window);
		m_Window = nullptr;
	}
	glfwTerminate();
}

// IWindow Interface Implementation =====================

void OpenGLWindow::init() {
	if (!glfwInit()) 
		throw std::runtime_error("OpenGLWindow: glfwInit() failed");
	
	setGLFWHints();

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

	if (!m_Window) {
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

void OpenGLWindow::update() {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

bool OpenGLWindow::shouldClose() {
	return glfwWindowShouldClose(m_Window);
}

int OpenGLWindow::getWidth()  const { return m_Width; }
int OpenGLWindow::getHeight() const { return m_Height; }

void OpenGLWindow::setGLFWHints() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Defaults::GL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Defaults::GL_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // required on macOS
#endif
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
}

void OpenGLWindow::setBackgroundColor(float red, float green, float blue, float alpha) {
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWindow::setBackgroundColor(Color color) {
	setBackgroundColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}