#include "Plane.h"

Plane::Plane() 
{
}

Plane::Plane(int horizontalQuadCount)
{
	_horizontalQuadCount = horizontalQuadCount;
}

void Plane::Draw()
{
	Vector2 pos(-0.5f, -0.5f);

	float quadDistance = 1 / _horizontalQuadCount;

	glBegin(GL_QUADS);

	for (int i = 0; i < _horizontalQuadCount; i++)
	{
		for (int j = 0; j < _horizontalQuadCount; j++)
		{
			glVertex2f(pos._x + quadDistance * i, pos._y + quadDistance * j);
			glVertex2f(pos._x + quadDistance * i, pos._y + quadDistance * j + 1);
			glVertex2f(pos._x + quadDistance * i + 1, pos._y + quadDistance * j + 1);
			glVertex2f(pos._x + quadDistance * i + 1, pos._y + quadDistance * j);
		}
	}

	glEnd();
}
