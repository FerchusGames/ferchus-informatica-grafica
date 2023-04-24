#include "plane.h"

#include <GL/glew.h>
#include "vector2.h"

plane::plane(const int& horizontal_quad_count)
{
	horizontal_quad_count_ = horizontal_quad_count;
}

plane::plane(const vector2& position, const vector2& scale, const int& horizontal_quad_count)
{
	position_ = position;
	scale_ = scale;
	horizontal_quad_count_ = horizontal_quad_count;
}

void plane::draw() const
{
	glPushMatrix();

		glTranslatef(position_.x, position_.y, 0.0f);
		glScalef(scale_.x, scale_.y, 1.0f);

		const vector2 vertex_position(-0.5f, -0.5f);

		const float quad_distance = 1.0f / static_cast<float>(horizontal_quad_count_);

		glBegin(GL_QUADS);

		for (int i = 0; i < horizontal_quad_count_; i++)
		{
			for (int j = 0; j < horizontal_quad_count_; j++)
			{
				//glColor3f((pos._x + quadDistance * i) + 0.5f, (pos._y + quadDistance * j) + 0.5f, 0);
				
				glVertex2f(vertex_position.x + quad_distance * (i + 1), vertex_position.y + quad_distance * j);
				glVertex2f(vertex_position.x + quad_distance * (i + 1), vertex_position.y + quad_distance * (j + 1));
				glVertex2f(vertex_position.x + quad_distance * i, vertex_position.y + quad_distance * (j + 1));
				glVertex2f(vertex_position.x + quad_distance * i, vertex_position.y + quad_distance * j);
			}
		}

		glEnd();

	glPopMatrix();
}
