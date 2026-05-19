#pragma once

#include <graphics/shapes/2d/Rectangle.h>

class OpenGLRectangleBatch {
public:
	OpenGLRectangleBatch();
	~OpenGLRectangleBatch();

	void draw(const Rectangle& rectangle);

private:
	void init();
	void destroy();

	unsigned int m_vao = 0;
	unsigned int m_vbo = 0;
	unsigned int m_ebo = 0;
};