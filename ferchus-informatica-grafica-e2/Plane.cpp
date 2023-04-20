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
	vector2 pos(-0.5f, -0.5f);

	float quadDistance = 1.0f / _horizontalQuadCount;

	glBegin(GL_QUADS);

	for (int i = 0; i < _horizontalQuadCount; i++)
	{
		for (int j = 0; j < _horizontalQuadCount; j++)
		{
			//glColor3f((pos._x + quadDistance * i) + 0.5f, (pos._y + quadDistance * j) + 0.5f, 0);
			
			glVertex2f(pos.x + quadDistance * (i + 1), pos.y + quadDistance * j);
			glVertex2f(pos.x + quadDistance * (i + 1), pos.y + quadDistance * (j + 1));
			glVertex2f(pos.x + quadDistance * i, pos.y + quadDistance * (j + 1));
			glVertex2f(pos.x + quadDistance * i, pos.y + quadDistance * j);
		}
	}

	glEnd();
}
