#include <graphics/shapes/Color.h>

#include <algorithm>
#include <cstdlib>

const Color Color::White = { 255, 255, 255, 255 };
const Color Color::Black = { 0,   0,   0, 255 };
const Color Color::Red = { 255,   0,   0, 255 };
const Color Color::Green = { 0, 255,   0, 255 };
const Color Color::Blue = { 0,   0, 255, 255 };
const Color Color::Yellow = { 255, 255,   0, 255 };
const Color Color::Cyan = { 0, 255, 255, 255 };
const Color Color::Magenta = { 255,   0, 255, 255 };
const Color Color::Transparent = { 0,   0,   0,   0 };

static unsigned char clampByte(float value) {
	return static_cast<unsigned char>(std::max(0.0f, std::min(255.0f, value)));
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
	: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {
}

unsigned char Color::getRed()   const { return m_red; }
unsigned char Color::getGreen() const { return m_green; }
unsigned char Color::getBlue()  const { return m_blue; }
unsigned char Color::getAlpha() const { return m_alpha; }

void Color::setRed(float red) {
	m_red = clampByte(red);
}

void Color::setGreen(float green) {
	m_green = clampByte(green);
}

void Color::setBlue(float blue) {
	m_blue = clampByte(blue);
}

void Color::setAlpha(float alpha) {
	m_alpha = clampByte(alpha);
}

void Color::setRGBA(float red, float green, float blue, float alpha) {
	m_red = clampByte(red);
	m_green = clampByte(green);
	m_blue = clampByte(blue);
	m_alpha = clampByte(alpha);
}

float Color::normalizeRed()   const { return m_red / 255.0f; }
float Color::normalizeGreen() const { return m_green / 255.0f; }
float Color::normalizeBlue()  const { return m_blue / 255.0f; }
float Color::normalizeAlpha() const { return m_alpha / 255.0f; }

Color Color::operator+(const Color& o) const {
    return Color(
        clampByte(m_red + o.m_red),
        clampByte(m_green + o.m_green),
        clampByte(m_blue + o.m_blue),
        clampByte(m_alpha + o.m_alpha)
    );
}

Color Color::operator*(float s) const {
    return Color(
        clampByte(m_red * s),
        clampByte(m_green * s),
        clampByte(m_blue * s),
        clampByte(m_alpha * s)
    );
}

bool Color::operator==(const Color& o) const {
    return m_red == o.m_red && m_green == o.m_green && m_blue == o.m_blue && m_alpha == o.m_alpha;
}

bool Color::operator!=(const Color& o) const {
    return !(*this == o);
}