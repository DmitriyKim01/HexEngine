#include <graphics/shapes/2d/Triangle.h>
#include <stdexcept>

Triangle::Triangle(Position position, float width, float height, Color color)
	: Shape2D(position, color), m_width(width), m_height(height)
{
	if (width <= 0.0f)
	{
		throw std::invalid_argument("Triangle's width must be a positive value.");
	}
	if (height <= 0.0f)
	{
		throw std::invalid_argument("Triangle's height must be a positive value.");
	}
}
Triangle::Triangle(Position position, int width, int height, Color color)
	: Triangle(position, static_cast<float>(width), static_cast<float>(height), color)
{}

Triangle::Triangle(float x, float y, float width, float height, Color color)
	: Triangle(Position(x, y), width, height, color)
{}

Triangle::Triangle(int x, int y, int width, int height, Color color)
	: Triangle(Position(static_cast<float>(x), static_cast<float>(y)), width, height, color)
{}

Triangle::Triangle(float x, float y, float z, float width, float height, Color color)
	: Triangle(Position(x, y, z), width, height, color)
{}

Triangle::Triangle(int x, int y, int z, int width, int height, Color color)
	: Triangle(Position(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)),
				width,
				height,
				color)
{}

float Triangle::getHeight() const
{
	return m_height;
}

float Triangle::getWidth() const
{
	return m_width;
}

void Triangle::setHeight(float height)
{
	if (height <= 0.0f)
	{
		throw std::invalid_argument("Triangle's height must be a positive value.");
	}
	m_height = height;
}

void Triangle::setWidth(float width)
{
	if (width <= 0.0f)
	{
		throw std::invalid_argument("Triangle's width must be a positive value.");
	}
	m_width = width;
}

float Triangle::getArea() const
{
	return (m_width * m_height) / 2.0f;
}

std::array<float, 18> Triangle::getVertices() const
{
	float x = position.x;
	float y = position.y;
	float z = position.z;

	float r = color.getRed();
	float g = color.getGreen();
	float b = color.getBlue();

	return {
		// Bottom-left
		x, y, z, r, g, b,

		// Bottom-right
		x + m_width, y, z, r, g, b,

		// Top-center
		x + (m_width / 2.0f), y - m_height, z, r, g, b
	};
}

