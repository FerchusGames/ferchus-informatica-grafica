#include "vector3.h"

#include <cmath>

vector3::vector3(const float& _x, const float& _y, const float& _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float vector3::dot_product(const vector3& vector1, const vector3& vector2)
{
	return ((vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z));
}

vector3 vector3::cross_product(const vector3& vector1, const vector3& vector2)
{
	vector3 result;

	result.x = 1 * ((vector1.y * vector2.z) - (vector1.z * vector2.y));
	result.y = -1 * ((vector1.x * vector2.z) - (vector1.z * vector2.x));
	result.z = 1 * ((vector1.x * vector2.y) - (vector1.y * vector2.x));

	return result;
}

vector3 vector3::normalized() const
{
	const float magnitude = sqrt(static_cast<float>(pow(x, 2) + pow(y, 2) + pow(z, 2)));

	return {x / magnitude, y / magnitude, z / magnitude};
}

const vector3 vector3::zero(0, 0, 0);
const vector3 vector3::right(1, 0, 0);
const vector3 vector3::left(-1, 0, 0);
const vector3 vector3::up(0, 1, 0);
const vector3 vector3::down(0, -1, 0);
const vector3 vector3::forward(0, 0, 1);
const vector3 vector3::backward(0, 0, -1);