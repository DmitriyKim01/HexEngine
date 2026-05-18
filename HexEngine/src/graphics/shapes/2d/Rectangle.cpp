#include <graphics/shapes/2d/Rectangle.h>
#include <stdexcept>

Rectangle::Rectangle(Position position, float width, float height, Color color)
	: Shape2D(position, color), m_width(width), m_height(height)
{
	if (width <= 0.0f)
	{
		throw std::invalid_argument("Rectangle's width must be a positive value.");
	}
	if (height <= 0.0f)
	{
		throw std::invalid_argument("Rectangle's height must be a positive value.");
	}
}
Rectangle::Rectangle(Position position, int width, int height, Color color)
	: Rectangle(position, static_cast<float>(width), static_cast<float>(height), color)
{}

Rectangle::Rectangle(float x, float y, float width, float height, Color color)
	: Rectangle(Position(x, y), width, height, color)
{}

Rectangle::Rectangle(int x, int y, int width, int height, Color color)
	: Rectangle(Position(static_cast<float>(x), static_cast<float>(y)), width, height, color)
{}

Rectangle::Rectangle(float x, float y, float z, float width, float height, Color color)
	: Rectangle(Position(x, y, z), width, height, color)
{}

Rectangle::Rectangle(int x, int y, int z, int width, int height, Color color)
	: Rectangle(Position(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)),
				width,
				height,
				color)
{}

float Rectangle::getHeight() const
{
	return m_height;
}

float Rectangle::getWidth() const
{
	return m_width;
}

void Rectangle::setHeight(float height)
{
	if (height <= 0.0f)
	{
		throw std::invalid_argument("Rectangle's height must be a positive value.");
	}
	m_height = height;
}

void Rectangle::setWidth(float width)
{
	if (width <= 0.0f)
	{
		throw std::invalid_argument("Rectangle's width must be a positive value.");
	}
	m_width = width;
}

float Rectangle::getArea() const
{
	return m_width * m_height;
}

std::array<float, 24> Rectangle::getVertices() const
{
	float left = position.x;
	float right = position.x + getWidth();
	float top = position.y;
	float bottom = position.y + getHeight();
	float z = position.z;

	float red = color.getRed();
	float green = color.getGreen();
	float blue = color.getBlue();

	return {
		left,  top,    z,  red, green, blue,
		right, top,    z,  red, green, blue,
		right, bottom, z,  red, green, blue,
		left,  bottom, z,  red, green, blue,
	};
}

