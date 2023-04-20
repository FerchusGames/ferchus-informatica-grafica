#include "collider2d.h"

collider2d::collider2d(const float& top, const float& bottom, const float& left, const float& right)
{
	top_ = top;
	bottom_ = bottom;
	left_ = left;
	right_ = right;
}

bool collider2d::check_collisions(const collider2d& other) const
{
	return (top_ + position_.y > other.bottom_ + other.position_.y || bottom_ + position_.y < other.top_ + other.position_.y)
		&& (right_ + position_.x > other.left_ + other.position_.x || left_ + position_.x < other.right_ + other.position_.x);
}

void collider2d::move(const vector2& position)
{
	position_ = position;
}
