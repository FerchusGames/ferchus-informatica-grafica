#pragma once
struct Vector3
{
	float _x = 0, _y = 0, _z = 0;

	Vector3() {}

	Vector3(float x, float y, float z);

#pragma region Vectors

	static Vector3 zero();
	static Vector3 right();
	static Vector3 left();
	static Vector3 up();
	static Vector3 down();
	static Vector3 forward();
	static Vector3 backward();

#pragma endregion
};
