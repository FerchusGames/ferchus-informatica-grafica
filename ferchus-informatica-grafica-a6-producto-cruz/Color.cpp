#include "Color.h"

Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	_r = r;
	_g = g;
	_b = b;
}

void Color::Add(unsigned char difference)
{
	_r += difference;
	_g += difference;
	_b += difference;
}

#pragma region Colors

Color Color::red()
{
	return Color(255, 0, 0);
}

Color Color::green()
{
	return Color(0, 255, 0);
}

Color Color::blue()
{
	return Color(0, 0, 255);
}

Color Color::yellow()
{
	return Color(255, 255, 0);
}

Color Color::cyan()
{
	return Color(0, 255, 255);
}

Color Color::magenta()
{
	return Color(255, 0, 255);
}

Color Color::black()
{
	return Color(0, 0 , 0);
}

Color Color::gray()
{
	return Color(127, 127, 127);
}

Color Color::white()
{
	return Color(255, 255, 255);
}

#pragma endregion
