#include "paddle.h"

void paddle::draw()
{
	plane_.draw();
}

void paddle::update()
{
	collider_.move(position_);
}

void paddle::set_speed(const float& speed)
{
	speed_ = speed;
}
