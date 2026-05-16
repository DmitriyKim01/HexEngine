#pragma once

#include <graphics/window/Window.h>
#include <GLFW/glfw3.h>
#include <string>

class GLFWindow : public Window {
private:
	int m_Width;
	int m_Height;
	std::string m_Title;
	GLFWwindow* m_Window = nullptr;

	void init();
	void setGLFWHints();
	static int validateDimension(int value, const std::string& name);

public:
	struct Defaults {
		static constexpr int WIDTH = 1280;
		static constexpr int HEIGHT = 720;
		static constexpr const char* TITLE = "OpenGL Window";
		static constexpr int         GL_MAJOR = 3;
		static constexpr int         GL_MINOR = 3;
	};

	GLFWindow();
	GLFWindow(int width, int height);
	GLFWindow(int width, int height, const std::string& title);
	~GLFWindow();

	void pollEvents()		override;
	void swapBuffers()		override;
	bool shouldClose()	override;
	void shutdown() 	override;

	int getWidth()	const override;
	int getHeight() const override;

};