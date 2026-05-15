#pragma once

#include "../../core/IWindow.h"
#include <GLFW/glfw3.h>
#include <string>

class OpenGLWindow : public IWindow {
public:
	struct Defaults {
		static constexpr int WIDTH = 1280;
		static constexpr int HEIGHT = 720;
		static constexpr const char* TITLE = "OpenGL Window";
		static constexpr int         GL_MAJOR = 3;
		static constexpr int         GL_MINOR = 3;
	};

	OpenGLWindow();
	OpenGLWindow(int width, int height);
	OpenGLWindow(int width, int height, const std::string& title);
	~OpenGLWindow();

	void update()		override;
	bool shouldClose()	override;

	int getWidth()	const override;
	int getHeight() const override;

private:
	GLFWwindow* m_Window = nullptr;
	int m_Width;
	int m_Height;
	std::string m_Title;

	void init();
	void setGLFWHints();
	static int validateDimension(int value, const std::string& name);
};