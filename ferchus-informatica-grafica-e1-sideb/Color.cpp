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
