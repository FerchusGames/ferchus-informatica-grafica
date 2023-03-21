#pragma once
struct Vector2
{
	float _x = 0, _y = 0;

	Vector2() {}

	Vector2(float x, float y);

#pragma region Vectors

	Vector2 zero();
	Vector2 right();
	Vector2 left();
	Vector2 up();
	Vector2 down();

#pragma endregion
};
