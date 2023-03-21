#pragma once
struct Color
{
	unsigned char _r = 255;
	unsigned char _g = 255;
	unsigned char _b = 255;

	Color() {}

	Color(unsigned char r, unsigned char g, unsigned char b);

	void Add(unsigned char difference);

#pragma region Colors

	Color red();
	Color green();
	Color blue();
	Color yellow();
	Color cyan();
	Color magenta();
	Color black();
	Color gray();
	Color white();

#pragma endregion
};

