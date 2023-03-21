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

	static Color red();
	static Color green();
	static Color blue();
	static Color yellow();
	static Color cyan();
	static Color magenta();
	static Color black();
	static Color gray();
	static Color white();

#pragma endregion
};

