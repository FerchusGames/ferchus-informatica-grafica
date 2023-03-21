#pragma once
struct Vector2
{
	float _x = 0, _y = 0;

	Vector2() {}

	Vector2(float x, float y);

#pragma region Vectors

	static Vector2 zero();
	static Vector2 right();
	static Vector2 left();
	static Vector2 up();
	static Vector2 down();

#pragma endregion
};
