#include "Color.h"

Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	_r = r;
	_g = g;
	_b = b;
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	_r = r;
	_g = g;
	_b = b;
	_a = a;
}

void Color::Add(unsigned char difference)
{
	_r += difference;
	_g += difference;
	_b += difference;
}

Color Color::red(255, 0, 0);
Color Color::green(0, 255, 0);
Color Color::blue(0, 0, 255);
Color Color::yellow(255, 255, 0);
Color Color::cyan(0, 255, 255);
Color Color::magenta(255, 0, 255);
Color Color::black(0, 0, 0);
Color Color::gray(127, 127, 127);
Color Color::white(255, 255, 255);