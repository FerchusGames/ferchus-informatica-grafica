#include "Cube.h"
#include <iostream>

using namespace std;

Cube::Cube()
{
	_scale = (float)(rand() % 1001) ;

	_speed = RandomFloat();
	_color = Color(RandomUChar() / 2, RandomUChar() / 2, RandomUChar() / 2);
}

void Cube::SetPosition(Vector3 position)
{
	_position = position;
}

void Cube::Draw()
{
	float halfScale = _scale / 2;

	glBegin(GL_QUADS);

	glColor3ub(_color._r, _color._g, _color._b);

		// Bottom
		glVertex3f(-halfScale, -halfScale, -halfScale);
		glVertex3f(halfScale, -halfScale, -halfScale);
		glVertex3f(halfScale, -halfScale, halfScale);
		glVertex3f(-halfScale, -halfScale, halfScale);

		// Front
		glVertex3f(-halfScale, -halfScale, halfScale);
		glVertex3f(halfScale, -halfScale, halfScale);
		glVertex3f(halfScale, halfScale, halfScale);
		glVertex3f(-halfScale, halfScale, halfScale);

		// Right
		glVertex3f(halfScale, -halfScale, halfScale);
		glVertex3f(halfScale, -halfScale, -halfScale);
		glVertex3f(halfScale, halfScale, -halfScale);
		glVertex3f(halfScale, halfScale, halfScale);

		// Back
		glVertex3f(halfScale, -halfScale, -halfScale);
		glVertex3f(-halfScale, -halfScale, -halfScale);
		glVertex3f(-halfScale, halfScale, -halfScale);
		glVertex3f(halfScale, halfScale, -halfScale);

		// Left
		glVertex3f(-halfScale, -halfScale, -halfScale);
		glVertex3f(-halfScale, -halfScale, halfScale);
		glVertex3f(-halfScale, halfScale, halfScale);
		glVertex3f(-halfScale, halfScale, -halfScale);

		// Top
		glVertex3f(-halfScale, halfScale, halfScale);
		glVertex3f(halfScale, halfScale, halfScale);
		glVertex3f(halfScale, halfScale, -halfScale);
		glVertex3f(-halfScale, halfScale, -halfScale);



	glEnd();
}