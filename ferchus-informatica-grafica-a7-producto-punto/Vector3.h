#pragma once

#include <cmath>

struct Vector3
{
	float _x = 0, _y = 0, _z = 0;

	Vector3() {}

	Vector3(float x, float y, float z);

	const static float DotProduct(Vector3 vector1, Vector3 vector2);

	const static Vector3 CrossProduct(Vector3 vector1, Vector3 vector2);

	const Vector3 normalized();

	const static Vector3 zero;
	const static Vector3 right;
	const static Vector3 left;
	const static Vector3 up;
	const static Vector3 down;
	const static Vector3 forward;
	const static Vector3 backward;
};
