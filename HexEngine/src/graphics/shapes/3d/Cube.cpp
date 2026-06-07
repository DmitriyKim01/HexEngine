#include <graphics/shapes/3d/Cube.h>
#include <stdexcept>

Cube::Cube(Position position, float width, float height, float depth, Color color)
    : Shape3D(position, color), m_width(width), m_height(height), m_depth(depth)
{
    if (width <= 0.0f)
    {
        throw std::invalid_argument("Cube's width must be a positive value.");
    }
    if (height <= 0.0f)
    {
        throw std::invalid_argument("Cube's height must be a positive value.");
    }
    if (depth <= 0.0f)
    {
        throw std::invalid_argument("Cube's depth must be a positive value.");
    }
}

Cube::Cube(Position position, int width, int height, int depth, Color color)
    : Cube(position,
           static_cast<float>(width),
           static_cast<float>(height),
           static_cast<float>(depth),
           color)
{}

Cube::Cube(float x, float y, float width, float height, float depth, Color color)
    : Cube(Position(x, y), width, height, depth, color)
{}

Cube::Cube(int x, int y, int width, int height, int depth, Color color)
    : Cube(Position(static_cast<float>(x), static_cast<float>(y)),
           static_cast<float>(width),
           static_cast<float>(height),
           static_cast<float>(depth),
           color)
{}

Cube::Cube(float x, float y, float z, float width, float height, float depth, Color color)
    : Cube(Position(x, y, z), width, height, depth, color)
{}

Cube::Cube(int x, int y, int z, int width, int height, int depth, Color color)
    : Cube(Position(static_cast<float>(x),
                    static_cast<float>(y),
                    static_cast<float>(z)),
           static_cast<float>(width),
           static_cast<float>(height),
           static_cast<float>(depth),
           color)
{}

float Cube::getWidth() const
{
    return m_width;
}

float Cube::getHeight() const
{
    return m_height;
}

float Cube::getDepth() const
{
    return m_depth;
}

void Cube::setWidth(float width)
{
    if (width <= 0.0f)
    {
        throw std::invalid_argument("Cube's width must be a positive value.");
    }

    m_width = width;
}

void Cube::setHeight(float height)
{
    if (height <= 0.0f)
    {
        throw std::invalid_argument("Cube's height must be a positive value.");
    }

    m_height = height;
}

void Cube::setDepth(float depth)
{
    if (depth <= 0.0f)
    {
        throw std::invalid_argument("Cube's depth must be a positive value.");
    }

    m_depth = depth;
}

float Cube::getVolume() const
{
    return m_width * m_height * m_depth;
}

std::array<float, 48> Cube::getVertices() const
{
    float left = position.x;
    float right = position.x + getWidth();

    float top = position.y;
    float bottom = position.y + getHeight();

    float front = position.z;
    float back = position.z + getDepth();

    float red = color.getRed();
    float green = color.getGreen();
    float blue = color.getBlue();

    return {
        // x, y, z, r, g, b

        // Front corners
        left,  top,    front, red, green, blue, // 0
        right, top,    front, red, green, blue, // 1
        right, bottom, front, red, green, blue, // 2
        left,  bottom, front, red, green, blue, // 3

        // Back corners
        left,  top,    back, red, green, blue, // 4
        right, top,    back, red, green, blue, // 5
        right, bottom, back, red, green, blue, // 6
        left,  bottom, back, red, green, blue, // 7
    };
}