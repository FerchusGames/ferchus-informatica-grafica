#include "paddle.h"

#include "game_time.h"
#include "input.h"
#include "GL/glew.h"
#include <algorithm>
#include <iostream>

paddle::paddle() : game_object2d(vector2::zero) {}

paddle::paddle(const vector2& position) : game_object2d(position, vector2(1.0f, 0.2f))
{
	collider_.translate(position_);
}

paddle::paddle(const vector2& position, const float& speed) : game_object2d(position, vector2(1.0f, 0.2f))
{
	speed_ = speed;
}

paddle::paddle(const vector2& position, const vector2& scale) : paddle(position)
{
	scale_ = scale;
}

paddle::paddle(const vector2& position, const vector2& scale, const float& speed) : paddle(position, scale)
{
	speed_ = speed;
}


void paddle::draw()
{
	plane_.draw();
}

void paddle::update()
{
	collider_.translate(position_);

	if (collider_.check_collisions())
	{
		std::cout << "Paddle collision" << std::endl;
	}

	translate();

	glPushMatrix();
		glTranslatef(position_.x, position_.y, 0.0f);
		glScalef(scale_.x, scale_.y, 1.0f);
		draw();
	glPopMatrix();
}

void paddle::translate()
{
	position_.x += input::get_horizontal_axis() * speed_ * delta_time;

	position_.x = std::clamp(position_.x, -movement_limit_, movement_limit_);
}

void paddle::set_speed(const float& speed)
{
	speed_ = speed;
}
