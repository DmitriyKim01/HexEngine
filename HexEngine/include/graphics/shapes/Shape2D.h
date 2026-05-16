#pragma once

#include <graphics/shapes/Position.h>
#include <graphics/shapes/Color.h>

class Shape2D {
public:
	Position position;
	Color color;
	Shape2D(Position position, Color color);
};