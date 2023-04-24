#include "collider2d.h"

std::vector<collider2d*> collider2d::colliders_;

collider2d::collider2d(const vector2& scale) : scale_(scale)
{
	colliders_.push_back(this);
}

bool collider2d::check_collisions() const
{
	for (const auto& collider : colliders_)
	{
		if (collider != this)
		{
			if (is_colliding(collider))
			{
				return true;
			}
		}
	}

	return false;
}

bool collider2d::check_collisions(const vector2& next_position) const
{
	for (const auto& collider : colliders_)
	{
		if (collider != this)
		{
			if (is_colliding(next_position, collider))
			{
				return true;
			}
		}
	}
	return false;
}

bool collider2d::is_colliding(const collider2d* collider) const
{
	return is_colliding(position_, collider);
}

bool collider2d::is_colliding(const vector2& position, const collider2d* collider) const
{
	return
		(
			scale_.y / 2 + position.y > -collider->scale_.y / 2 + collider->position_.y // Top is over bottom
			&& scale_.y / 2 + position.y < collider->scale_.y / 2 + collider->position_.y // Top is under top
			|| -scale_.y / 2 + position.y < collider->scale_.y / 2 + collider->position_.y // Bottom is under top
			&& -scale_.y / 2 + position.y > -collider->scale_.y / 2 + collider->position_.y // Bottom is over bottom
		)
		&&
		(
			scale_.x / 2 + position.x > -collider->scale_.x / 2 + collider->position_.x // Right is over left
			&& scale_.x / 2 + position.x < collider->scale_.x / 2 + collider->position_.x // Right is under right
			|| -scale_.x / 2 + position.x < collider->scale_.x / 2 + collider->position_.x // Left is under right 
			&& -scale_.x / 2 + position.x > -collider->scale_.x / 2 + collider->position_.x // Left is over left
		);
}

void collider2d::translate(const vector2& position)
{
	position_ = position;
}
