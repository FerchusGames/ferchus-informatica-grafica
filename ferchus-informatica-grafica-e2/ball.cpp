#include "ball.h"

#include "game_time.h"
#include "GL/glew.h"
#include <iostream>

ball::ball() : game_object2d(vector2::zero, vector2(0.3f, 0.3f)) {}

ball::ball(const float& speed) : game_object2d(vector2::zero, vector2(0.3f, 0.3f))
{
	collider_.translate(position_);
	speed_ = speed;
}

ball::ball(const vector2& direction) : game_object2d(vector2::zero, vector2(0.3f, 0.3f))
{
	direction_ = direction;
}

ball::ball(const vector2& direction, const float& speed) : ball(direction)
{
	speed_ = speed;
}

void ball::change_direction(const bool& horizontal_change)
{
	if (horizontal_change)
	{
		direction_.x *= -1;
	}

	else
	{
		direction_.y *= -1;
	}
}

void ball::draw()
{
	 plane_.draw();
}

void ball::update()
{
	collider_.translate(position_);

	if (collider_.check_collisions(get_next_position()))
	{
		collider_.translate(position_);
		std::cout << "Ball collision" << std::endl;
		change_direction(false);
	}

	translate();

	glPushMatrix();
		glTranslatef(position_.x, position_.y, 0.0f);
		glScalef(scale_.x, scale_.y, 1.0f);
		draw();
	glPopMatrix();
}

void ball::translate() 
{
	position_ += direction_ * speed_ * delta_time;
}

float ball::get_speed() const
{
	return speed_;
}

vector2 ball::get_direction() const
{
	return direction_;
}

vector2 ball::get_next_position() const
{
	return position_ + (direction_ * speed_ * delta_time);
}

void ball::set_speed(const float& speed)
{
	speed_ = speed;
}
