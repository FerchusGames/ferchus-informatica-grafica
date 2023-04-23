#include "collider2d.h"

#include <ios>

collider2d::collider2d(const vector2& scale)
{
	scale_ = scale;
}

bool collider2d::check_collisions(const collider2d& other) const
{
	return (scale_.y / 2 + position_.y > -other.scale_.y / 2 + other.position_.y || -scale_.y / 2 + position_.y < other.scale_.y / 2 + other.position_.y)
		&& (scale_.x / 2 + position_.x > -other.scale_.x / 2 + other.position_.x || -scale_.x / 2 + position_.x < other.scale_.x / 2+ other.position_.x);
}

void collider2d::move(const vector2& position)
{
	position_ = position;
}
