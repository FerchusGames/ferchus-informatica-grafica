#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

const Vector3 Vector3::CrossProduct(Vector3 vector1, Vector3 vector2)
{
	Vector3 result;

	result._x = 1 * ((vector1._y * vector2._z) - (vector1._z * vector2._y));
	result._y = -1 * ((vector1._x * vector2._z) - (vector1._z * vector2._x));
	result._z = 1 * ((vector1._x * vector2._y) - (vector1._y * vector2._x));

	return result;
}

Vector3 Vector3::zero(0, 0, 0);
Vector3 Vector3::right(1, 0, 0);
Vector3 Vector3::left(-1, 0, 0);
Vector3 Vector3::up(0, 1, 0);
Vector3 Vector3::down(0, -1, 0);
Vector3 Vector3::forward(0, 0, 1);
Vector3 Vector3::backward(0, 0, -1);