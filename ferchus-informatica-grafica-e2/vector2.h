#pragma once

struct vector2
{
	float x = 0, y = 0;

	vector2() = default;

	vector2(const float& _x, const float& _y);

	static float dot_product(const vector2& vector1, const vector2& vector2);

	vector2 normalized() const;

	vector2 operator*(const float& scalar) const;
	vector2 operator/(const float& scalar) const;
	vector2 operator+(const vector2& other) const;
	vector2 operator+(const float& scalar) const;
	vector2 operator-(const vector2& other) const;
	vector2 operator-(const float& scalar) const;
	vector2& operator+=(const vector2& other);
	vector2& operator+=(const float& scalar);
	vector2& operator-=(const vector2& other);
	vector2& operator-=(const float& scalar);

	const static vector2 zero;
	const static vector2 right;
	const static vector2 left;
	const static vector2 up;
	const static vector2 down;
};
