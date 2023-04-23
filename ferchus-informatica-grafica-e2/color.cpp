#include "color.h"

#include "random.h"

color::color(const float& _r, const float& _g, const float& _b)
{
	r = _r;
	g = _g;
	b = _b;
}

color::color(const float& _r, const float& _g, const float& _b, const float& _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void color::add(const float& difference)
{
	r += difference;
	g += difference;
	b += difference;
}

void color::randomize_rgb()
{
	r = random_percentage();
	g = random_percentage();
	b = random_percentage();
}

void color::randomize_rgba()
{
	r = random_percentage();
	g = random_percentage();
	b = random_percentage();
	a = random_percentage();
}

float* color::to_array() const
{
		float* array = new float[4];
		array[0] = r;
		array[1] = g;
		array[2] = b;
		array[3] = a;
		return array;
}

color color::red(1.0f, 0.0f, 0.0f);
color color::green(0.0f, 1.0f, 0.0f);
color color::blue(0.0f, 0.0f, 1.0f);
color color::yellow(1.0f, 1.0f, 0.0f);
color color::cyan(0.0f, 1.0f, 1.0f);
color color::magenta(1.0f, 0.0f, 1.0f);
color color::black(0.0f, 0.0f, 0.0f);
color color::gray(0.5f, 0.5f, 0.5f);
color color::white(1.0f, 1.0f, 1.0f);