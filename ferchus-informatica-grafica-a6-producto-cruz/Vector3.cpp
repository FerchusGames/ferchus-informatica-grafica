#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector3 Vector3::zero()
{
	return Vector3(0, 0, 0);
}

Vector3 Vector3::right()
{
	return Vector3(1, 0, 0);
}

Vector3 Vector3::left()
{
	return Vector3(-1, 0 ,0);
}

Vector3 Vector3::up()
{
	return Vector3(0, 1, 0);
}

Vector3 Vector3::down()
{
	return Vector3(0, -1, 0);
}

Vector3 Vector3::forward()
{
	return Vector3(0, 0, 1);
}

Vector3 Vector3::backward()
{
	return Vector3(0, 0, -1);
}
