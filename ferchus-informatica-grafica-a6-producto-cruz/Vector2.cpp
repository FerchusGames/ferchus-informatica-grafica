#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	_x = x;
	_y = y;
}

Vector2 Vector2::zero()
{
	return Vector2(0, 0);
}

Vector2 Vector2::right()
{
	return Vector2(1, 0);
}

Vector2 Vector2::left()
{
	return Vector2(-1, 0);
}

Vector2 Vector2::up()
{
	return Vector2(0, 1);
}

Vector2 Vector2::down()
{
	return Vector2(0, -1);
}
