#pragma once
#pragma once

#include <graphics/shapes/2d/Triangle.h>

class OpenGLTriangleBatch {
public:
	OpenGLTriangleBatch();
	~OpenGLTriangleBatch();

	void draw(const Triangle& triangle);

private:
	void init();
	void destroy();

	unsigned int m_vao = 0;
	unsigned int m_vbo = 0;
	unsigned int m_ebo = 0;
};