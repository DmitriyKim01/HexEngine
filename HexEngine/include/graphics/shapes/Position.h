#pragma once

class Position {
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	Position() = default;
	Position(float x, float y);
	Position(int x, int y);
	Position(float x, float y, float z);
	Position(int x, int y, int z);
};