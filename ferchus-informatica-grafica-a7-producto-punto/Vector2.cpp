#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	_x = x;
	_y = y;
}

Vector2 Vector2::zero(0, 0);
Vector2 Vector2::right(1, 0);
Vector2 Vector2::left(-1, 0);
Vector2 Vector2::up(0, 1);
Vector2 Vector2::down(0, -1);
