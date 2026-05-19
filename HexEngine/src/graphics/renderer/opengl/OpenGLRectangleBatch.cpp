#include <graphics/shapes/2d/Rectangle.h>
#include <graphics/renderer/opengl/OpenGLRectangleBatch.h>

#include <glad/glad.h>

OpenGLRectangleBatch::OpenGLRectangleBatch()
{
    init();
}

OpenGLRectangleBatch::~OpenGLRectangleBatch()
{
    destroy();
}

void OpenGLRectangleBatch::init()
{
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, nullptr, GL_DYNAMIC_DRAW);

    static constexpr unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void OpenGLRectangleBatch::destroy()
{
    if (m_ebo != 0) { glDeleteBuffers(1, &m_ebo); m_ebo = 0; }
    if (m_vbo != 0) { glDeleteBuffers(1, &m_vbo); m_vbo = 0; }
    if (m_vao != 0) { glDeleteVertexArrays(1, &m_vao); m_vao = 0; }
}

void OpenGLRectangleBatch::draw(const Rectangle& rectangle)
{
    std::array<float, 24> vertices = rectangle.getVertices();

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices.data());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}