#pragma once

#include <graphics/shapes/3d/Cube.h>

class OpenGLCubeBatch {
public:
    OpenGLCubeBatch();
    ~OpenGLCubeBatch();

    void draw(const Cube& cube);

private:
    void init();
    void destroy();

    unsigned int m_vao = 0;
    unsigned int m_vbo = 0;
    unsigned int m_ebo = 0;
};