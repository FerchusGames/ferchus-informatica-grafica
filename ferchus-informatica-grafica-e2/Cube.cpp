#include "cube.h"

#include <GL/glew.h>
#include <iostream>
#include "Random.h"

using namespace std;

cube::cube()
{
	color_ = color(random_percentage() / 2, random_percentage() / 2, random_percentage() / 2);
}

void cube::set_position(vector3 position)
{
	position_ = position;
}

void cube::set_color(color color)
{
	color_ = color;

	color_.r /= 2;
	color_.g /= 2;
	color_.b /= 2;
}

void cube::set_scale(float scale)
{
	scale_ = scale;
}

void cube::draw() const
{
	color color = color_;

	glPushMatrix();

	glTranslatef(position_.x, position_.y, position_.z);
	glScalef(scale_, scale_, scale_);

		glBegin(GL_QUADS);

#pragma region Vertex
			// Bottom
			glColor3f(color.r, color.g, color.b);

			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(-0.5f, -0.5f, 0.5f);

			// Front
			color.add(color_change_);
			glColor3f(color.r, color.g, color.b);

			glVertex3f(-0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, 0.5f);

			// Right
			color.add(color_change_);
			glColor3f(color.r, color.g, color.b);

			glVertex3f(0.5f, -0.5f, 0.5f);
			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);

			// Back
			color.add(color_change_);
			glColor3ub(color.r, color.g, color.b);

			glVertex3f(0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);

			// Left
			color.add(color_change_);
			glColor3ub(color.r, color.g, color.b);

			glVertex3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(-0.5f, -0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, 0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);

			// Top
			color.add(color_change_);
			glColor3f(color.r, color.g, color.b);

			glVertex3f(-0.5f, 0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, -0.5f);
			glVertex3f(-0.5f, 0.5f, -0.5f);

		glEnd();
#pragma endregion
	glPopMatrix();
}


