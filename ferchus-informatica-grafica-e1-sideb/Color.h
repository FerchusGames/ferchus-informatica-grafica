#pragma once
struct Color
{
	unsigned char _r = 255;
	unsigned char _g = 255;
	unsigned char _b = 255;

	Color() {}

	Color(unsigned char r, unsigned char g, unsigned char b);

	void Add(unsigned char difference);
};

