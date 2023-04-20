#pragma once

struct vector3
{
	float x = 0, y = 0, z = 0;

	vector3() = default;

	vector3(const float& _x, const float& _y, const float& _z);

	static float dot_product(const vector3& vector1, const vector3& vector2);

	static vector3 cross_product(const vector3& vector1, const vector3& vector2);

	vector3 normalized() const;

	const static vector3 zero;
	const static vector3 right;
	const static vector3 left;
	const static vector3 up;
	const static vector3 down;
	const static vector3 forward;
	const static vector3 backward;
};
