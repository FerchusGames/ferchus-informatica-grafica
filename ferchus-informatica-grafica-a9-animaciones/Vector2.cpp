#include "Vector2.h"

using namespace std;

Vector2::Vector2(float x, float y)
{
	_x = x;
	_y = y;
}

const float Vector2::DotProduct(Vector2 vector1, Vector2 vector2)
{
	return ((vector1._x * vector2._x) + (vector1._y * vector2._y));
}

const Vector2 Vector2::normalized()
{
	float magnitude = sqrt(pow(_x, 2) + pow(_y, 2));

	return Vector2(_x / magnitude, _y / magnitude);
}

const Vector2 Vector2::zero(0, 0);
const Vector2 Vector2::right(1, 0);
const Vector2 Vector2::left(-1, 0);
const Vector2 Vector2::up(0, 1);
const Vector2 Vector2::down(0, -1);
