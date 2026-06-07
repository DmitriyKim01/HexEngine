#include <graphics/renderer/opengl/OpenGLCubeBatch.h>
#include <graphics/shapes/3d/Cube.h>

#include <glad/glad.h>

#include <array>

OpenGLCubeBatch::OpenGLCubeBatch()
{
    init();
}

OpenGLCubeBatch::~OpenGLCubeBatch()
{
    destroy();
}

void OpenGLCubeBatch::init()
{
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 48, nullptr, GL_DYNAMIC_DRAW);

    static constexpr unsigned int indices[] = {
        // Front face
        0, 1, 2,
        2, 3, 0,

        // Back face
        5, 4, 7,
        7, 6, 5,

        // Left face
        4, 0, 3,
        3, 7, 4,

        // Right face
        1, 5, 6,
        6, 2, 1,

        // Top face
        4, 5, 1,
        1, 0, 4,

        // Bottom face
        3, 2, 6,
        6, 7, 3
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Position: x, y, z
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)0
    );
    glEnableVertexAttribArray(0);

    // Color: r, g, b
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)(3 * sizeof(float))
    );
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void OpenGLCubeBatch::destroy()
{
    if (m_ebo != 0)
    {
        glDeleteBuffers(1, &m_ebo);
        m_ebo = 0;
    }

    if (m_vbo != 0)
    {
        glDeleteBuffers(1, &m_vbo);
        m_vbo = 0;
    }

    if (m_vao != 0)
    {
        glDeleteVertexArrays(1, &m_vao);
        m_vao = 0;
    }
}

void OpenGLCubeBatch::draw(const Cube& cube)
{
    std::array<float, 48> vertices = cube.getVertices();

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices.data());

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}