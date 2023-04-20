#include "color.h"

color::color(const unsigned char _r, const unsigned char _g, const unsigned char _b)
{
	r = _r;
	g = _g;
	b = _b;
}

color::color(const unsigned char _r, const unsigned char _g, const unsigned char _b, const unsigned char _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void color::add(const unsigned char difference)
{
	r += difference;
	g += difference;
	b += difference;
}

color color::red(255, 0, 0);
color color::green(0, 255, 0);
color color::blue(0, 0, 255);
color color::yellow(255, 255, 0);
color color::cyan(0, 255, 255);
color color::magenta(255, 0, 255);
color color::black(0, 0, 0);
color color::gray(127, 127, 127);
color color::white(255, 255, 255);