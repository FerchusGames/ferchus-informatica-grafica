#include "Cube.h"

Cube::Cube()
{
	_scale = RandomFloat();
	_speed = RandomFloat();
	_color = Color(RandomUChar() / 2, RandomUChar() / 2, RandomUChar() / 2);
}

void Cube::SetPosition(Vector3 position)
{
	_position = position;
}

void Cube::DrawCube()
{
	float halfScale = _scale / 2;

	glBegin(GL_QUADS);


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

	// Back
	glVertex3f(halfScale, -halfScale, -halfScale);
	glVertex3f(-halfScale, -halfScale, -halfScale);
	glVertex3f(-halfScale, halfScale, -halfScale);
	glVertex3f(halfScale, halfScale, -halfScale);

	glEnd();
}