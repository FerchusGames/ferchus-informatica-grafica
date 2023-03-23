#pragma once
struct Vector3
{
	float _x = 0, _y = 0, _z = 0;

	Vector3() {}

	Vector3(float x, float y, float z);

	const static Vector3 CrossProduct(Vector3 vector1, Vector3 vector2);

	static Vector3 zero;
	static Vector3 right;
	static Vector3 left;
	static Vector3 up;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 backward;
};
