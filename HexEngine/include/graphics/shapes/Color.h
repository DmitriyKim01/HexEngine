#pragma once

class Color {
private:
	unsigned char m_red	= 255;
	unsigned char m_green = 255;
	unsigned char m_blue	= 255;
	unsigned char m_alpha = 255;
public:
	// If add custom constructor, C++ does not automatically generate the default constructor anymore
	Color() = default;
	Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);

	// Getters
	unsigned char getRed()		const;
	unsigned char getGreen()	const;
	unsigned char getBlue()		const;
	unsigned char getAlpha()	const;

	// Setters
	void setRed(float red);
	void setGreen(float green);
	void setBlue(float blue);
	void setAlpha(float alpha);
	void setRGBA(float red, float green, float blue, float alpha = 255);

	// Normalized getters (0.0f - 1.0f)
	float normalizeRed() const;
	float normalizeGreen() const;
	float normalizeBlue() const;
	float normalizeAlpha() const;

	// Operators
	Color operator+(const Color& other) const;
	Color  operator*(float scalar)       const;
	bool   operator==(const Color& other) const;
	bool   operator!=(const Color& other) const;

	// Common presets
	static const Color White;
	static const Color Black;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Cyan;
	static const Color Magenta;
	static const Color Transparent;
};