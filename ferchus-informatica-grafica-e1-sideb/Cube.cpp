#include "Cube.h"
#include <iostream>

using namespace std;

Cube::Cube()
{
	do _scalePercentage = RandomPercentage(); while (_scalePercentage < _minScalePercentage);
	_scale = _scalePercentage * _scaleMultiplier;

	do _speedPercentage = RandomPercentage(); while (_speedPercentage < _minSpeedPercentage);
	_speed = _speedPercentage * _speedMultiplier;

	_color = Color(RandomUChar() / 2, RandomUChar() / 2, RandomUChar() / 2);
}

void Cube::SetPosition(Vector3 position)
{
	_position = position;
}

void Cube::Draw(float deltaTime)
{
	if (abs(_position._z + _speed * deltaTime) > _movementRange)
	{
		_speed *= -1;
	}

	_position._z += deltaTime * _speed;

	Color color = _color;

	glPushMatrix();

	glTranslatef(_position._x, _position._y, _position._z);
	glScalef(_scale, _scale, _scale);

		glBegin(GL_QUADS);

			// Bottom
			glColor3ub(color._r, color._g, color._b);

			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(-0.5f, -0.5f, 0.5f);

			// Front
			color.Add(_colorChange);
			glColor3ub(color._r, color._g, color._b);

			glVertex3f(-0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, 0.5f);

			// Right
			color.Add(_colorChange);
			glColor3ub(color._r, color._g, color._b);

			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);

			// Back
			color.Add(_colorChange);
			glColor3ub(color._r, color._g, color._b);

			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);

			// Left
			color.Add(_colorChange);
			glColor3ub(color._r, color._g, color._b);

			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, -0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);

			// Top
			color.Add(_colorChange);
			glColor3ub(color._r, color._g, color._b);

			glVertex3f(-0.5f, 0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);

		glEnd();

	glPopMatrix();
}