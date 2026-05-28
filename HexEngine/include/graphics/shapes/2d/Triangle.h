#pragma once

#include <graphics/shapes/Shape2D.h>
#include <graphics/shapes/Position.h>
#include <graphics/shapes/Color.h>

#include <array>

class Triangle : public Shape2D {
private:
	float m_width = 1.0f;
	float m_height = 1.0f;
public:
	Triangle(Position position, float width, float height, Color color);
	Triangle(Position position, int width, int height, Color color);

	Triangle(float x, float y, float width, float height, Color color);
	Triangle(int x, int y, int width, int height, Color color);

	Triangle(float x, float y, float z, float width, float height, Color color);
	Triangle(int x, int y, int z, int width, int height, Color color);

	float getWidth() const;
	float getHeight() const;

	void setWidth(float width);
	void setHeight(float height);

	float getArea() const;

	std::array<float, 18> getVertices() const;
};