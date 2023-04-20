#pragma once
struct color
{
	unsigned char r = 255;
	unsigned char g = 255;
	unsigned char b = 255;
	unsigned char a = 255;

	color() = default;

	color(unsigned char _r, unsigned char _g, unsigned char _b);
	color(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);

	void add(unsigned char difference);

	static color red;
	static color green;
	static color blue;
	static color yellow;
	static color cyan;
	static color magenta;
	static color black;
	static color gray;
	static color white;
};

