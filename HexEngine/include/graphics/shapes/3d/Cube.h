#pragma once

#include <graphics/shapes/3d/Shape3D.h>
#include <graphics/shapes/Position.h>
#include <graphics/shapes/Color.h>

#include <array>

class Cube : public Shape3D {
private:
	float m_width = 1.0f;
	float m_height = 1.0f;
	float m_depth = 1.0f;
public:
	Cube(Position position, float width, float height, float depth, Color color);
	Cube(Position position, int width, int height, int depth, Color color);

	Cube(float x, float y, float width, float height, float depth, Color color);
	Cube(int x, int y, int width, int height, int depth, Color color);

	Cube(float x, float y, float z, float width, float height, float depth, Color color);
	Cube(int x, int y, int z, int width, int height, int depth, Color color);

	float getWidth() const;
	float getHeight() const;
	float getDepth() const;

	void setWidth(float width);
	void setHeight(float height);
	void setDepth(float depth);

	float getVolume() const;

	std::array<float, 48> getVertices() const;
};