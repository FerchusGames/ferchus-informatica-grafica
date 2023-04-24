#include "block.h"

#include "GL/freeglut.h"
#include <iostream>

int block::count_ = 0;

block::block() : game_object2d(vector2::zero, vector2(0.7f, 0.5f))
{
	count_++;
}

block::block(const vector2& position) : game_object2d(vector2::zero, vector2(0.7f, 0.5f))
{
	count_++;
	collider_.translate(position_);
	set_position(position);
}

block::block(const vector2& position, const vector2& scale) : block(position)
{
	scale_ = scale;
}

void block::draw()
{
	plane_.draw();
}

void block::update()
{

	if (!is_enabled_)
	{
		return;
	}

	collider_.translate(position_);

	if (collider_.check_collisions())
	{
		count_--;
		set_enabled(false);
	}

	glPushMatrix();
		glTranslatef(position_.x, position_.y, 0.0f);
		glScalef(scale_.x, scale_.y, 1.0f);
		draw();
	glPopMatrix();
}

int block::get_count()
{
	return count_;
}
