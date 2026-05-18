#pragma once

#include <graphics/shapes/Shape2D.h>

#include <array>

class Rectangle : public Shape2D {
private:
	float m_Width = 1.0f;
	float m_Height = 1.0f;
public:
	Rectangle(Position position, float width, float height, Color color);
	Rectangle(float x, float y, float width, float height, Color color);
	Rectangle(float x, float y, float z, float width, float height, Color color);

	float getWidth() const;
	float getHeight() const;

	void setWidth(float width);
	void setHeight(float height);

	float getArea() const;

	std::array<float, 24> getVertices() const;
};