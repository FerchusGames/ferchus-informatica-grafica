#include "plane.h"

#include <GL/glew.h>
#include "vector2.h"

plane::plane(const int& _horizontal_quad_count)
{
	horizontal_quad_count_ = _horizontal_quad_count;
}

void plane::draw() const
{
	const vector2 pos(-0.5f, -0.5f);

	const float quad_distance = 1.0f / static_cast<float>(horizontal_quad_count_);

	glBegin(GL_QUADS);

	for (int i = 0; i < horizontal_quad_count_; i++)
	{
		for (int j = 0; j < horizontal_quad_count_; j++)
		{
			//glColor3f((pos._x + quadDistance * i) + 0.5f, (pos._y + quadDistance * j) + 0.5f, 0);
			
			glVertex2f(pos.x + quad_distance * (i + 1), pos.y + quad_distance * j);
			glVertex2f(pos.x + quad_distance * (i + 1), pos.y + quad_distance * (j + 1));
			glVertex2f(pos.x + quad_distance * i, pos.y + quad_distance * (j + 1));
			glVertex2f(pos.x + quad_distance * i, pos.y + quad_distance * j);
		}
	}

	glEnd();
}
