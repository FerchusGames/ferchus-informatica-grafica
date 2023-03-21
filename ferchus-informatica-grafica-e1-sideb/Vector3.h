#pragma once
struct Vector3
{
	float _x = 0, _y = 0, _z = 0;

	Vector3() {}

	Vector3(float x, float y, float z);

#pragma region Vectors

	Vector3 zero();
	Vector3 right();
	Vector3 left();
	Vector3 up();
	Vector3 down();
	Vector3 forward();
	Vector3 backward();

#pragma endregion
};
