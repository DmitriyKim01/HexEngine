#pragma once

#include <graphics/shapes/Position.h>
#include <graphics/shapes/Color.h>

class Shape3D {
public:
	Position position;
	Color color;
	Shape3D(Position position, Color color);
};