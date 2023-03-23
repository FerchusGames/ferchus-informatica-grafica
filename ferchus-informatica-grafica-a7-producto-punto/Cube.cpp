#include "Cube.h"

using namespace std;

Cube::Cube()
{
	do _speedPercentage = RandomPercentage(); while (_speedPercentage < _minSpeedPercentage);
	_speed = _speedPercentage * _speedMultiplier;

	_color = Color(RandomUChar() / 2, RandomUChar() / 2, RandomUChar() / 2);
}

void Cube::SetPosition(Vector3 position)
{
	_position = position;
}

void Cube::SetColor(Color color)
{
	_color = color;

	_color._r /= 2;
	_color._g /= 2;
	_color._b /= 2;
}

void Cube::SetScale(float scale)
{
	_scale = scale;
}

void Cube::Draw()
{
	Color color = _color;

	glPushMatrix();

	glTranslatef(_position._x, _position._y, _position._z);
	glScalef(_scale, _scale, _scale);

		glBegin(GL_QUADS);

#pragma region Vertex
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
#pragma endregion
	glPopMatrix();
}

void Cube::MoveBackAndForth(float deltaTime)
{
	if (abs(_position._z + _speed * deltaTime) > _movementRange)
	{
		_speed *= -1;
	}

	_position._z += deltaTime * _speed;
}
