#include <graphics/shapes/2d/Rectangle.h>
#include <stdexcept>

Rectangle::Rectangle(Position position, float width, float height, Color color)
	: Shape2D(position, color), m_Width(width), m_Height(height) {
	if (width <= 0.0f) {
		throw std::invalid_argument("Rectangle's width must be a positive value.");
	}
	if (height <= 0.0f) {
		throw std::invalid_argument("Rectangle's height must be a positive value.");
	}
}

Rectangle::Rectangle(float x, float y, float width, float height, Color color)
	: Rectangle(Position(x, y), width, height, color) {
}

Rectangle::Rectangle(float x, float y, float z, float width, float height, Color color)
	: Rectangle(Position(x, y, z), width, height, color) {
}

float Rectangle::getHeight() const {
	return m_Height;
}

float Rectangle::getWidth() const {
	return m_Width;
}

void Rectangle::setHeight(float height) {
	if (height <= 0.0f) {
		throw std::invalid_argument("Rectangle's height must be a positive value.");
	}
	m_Height = height;
}

void Rectangle::setWidth(float width) {
	if (width <= 0.0f) {
		throw std::invalid_argument("Rectangle's width must be a positive value.");
	}
	m_Width = width;
}

float Rectangle::getArea() const {
	return m_Width * m_Height;
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

