#pragma once
struct Color
{
	unsigned char _r = 255;
	unsigned char _g = 255;
	unsigned char _b = 255;
	unsigned char _a = 255;

	Color() {}

	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

	void Add(unsigned char difference);

	static Color red;
	static Color green;
	static Color blue;
	static Color yellow;
	static Color cyan;
	static Color magenta;
	static Color black;
	static Color gray;
	static Color white;
};

