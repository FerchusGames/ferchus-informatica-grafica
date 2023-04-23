#pragma once
struct color
{
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	float a = 1.0f;

	color() = default;

	color(const float& _r, const float& _g, const float& _b);
	color(const float& _r, const float& _g, const float& _b, const float& _a);

	void add(const float& difference);
	void randomize_rgb();
	void randomize_rgba();

	float* to_array() const;

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

