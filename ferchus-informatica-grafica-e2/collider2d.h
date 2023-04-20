#pragma once

#include  "vector2.h"

class collider2d
{
public:
	collider2d() = default;
	collider2d(const float& top, const float& bottom, const float& left, const float& right);

	bool check_collisions(const collider2d& other) const;

	void move(const vector2& position);

private:

	vector2 position_ = vector2(0.0f, 0.0f);

	float top_ = 0.5f;
	float bottom_ = 0.5f;
	float left_ = 0.5f;
	float right_ = 0.5f;
};
