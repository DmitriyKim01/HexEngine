#include <graphics/shapes/Position.h>

Position::Position(float x, float y) : x(x), y(y), z(0.0f) {}
Position::Position(int x, int y) : Position(static_cast<float>(x), static_cast<float>(y)) {}
Position::Position(float x, float y, float z) : x(x), y(y), z(z) {}
Position::Position(int x, int y, int z) : Position(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)) {}