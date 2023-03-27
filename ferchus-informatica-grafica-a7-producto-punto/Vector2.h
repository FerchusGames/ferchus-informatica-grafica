#pragma once

#include <cmath>

struct Vector2
{
	float _x = 0, _y = 0;

	Vector2() {}

	Vector2(float x, float y);

	const static float DotProduct(Vector2 vector1, Vector2 vector2);

	const Vector2 normalized();

	const static Vector2 zero;
	const static Vector2 right;
	const static Vector2 left;
	const static Vector2 up;
	const static Vector2 down;
};
