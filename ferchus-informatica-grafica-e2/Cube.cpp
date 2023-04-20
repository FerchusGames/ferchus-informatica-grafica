#include "Cube.h"

using namespace std;

Cube::Cube()
{
	do _speedPercentage = RandomPercentage(); while (_speedPercentage < _minSpeedPercentage);
	_speed = _speedPercentage * _speedMultiplier;

	_color = color(RandomUChar() / 2, RandomUChar() / 2, RandomUChar() / 2);
}

void Cube::SetPosition(vector3 position)
{
	_position = position;
}

void Cube::SetColor(color color)
{
	_color = color;

	_color.r /= 2;
	_color.g /= 2;
	_color.b /= 2;
}

void Cube::SetScale(float scale)
{
	_scale = scale;
}

void Cube::Draw()
{
	color color = _color;

	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);
	glScalef(_scale, _scale, _scale);

		glBegin(GL_QUADS);

#pragma region Vertex
			// Bottom
			glColor3ub(color.r, color.g, color.b);

			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(-0.5f, -0.5f, 0.5f);

			// Front
			color.add(_colorChange);
			glColor3ub(color.r, color.g, color.b);

			glVertex3f(-0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, 0.5f);

			// Right
			color.add(_colorChange);
			glColor3ub(color.r, color.g, color.b);

			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);

			// Back
			color.add(_colorChange);
			glColor3ub(color.r, color.g, color.b);

			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);

			// Left
			color.add(_colorChange);
			glColor3ub(color.r, color.g, color.b);

			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, -0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);

			// Top
			color.add(_colorChange);
			glColor3ub(color.r, color.g, color.b);

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
	if (abs(_position.z + _speed * deltaTime) > _movementRange)
	{
		_speed *= -1;
	}

	_position.z += deltaTime * _speed;
}
