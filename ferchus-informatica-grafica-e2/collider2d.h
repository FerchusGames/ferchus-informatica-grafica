#pragma once

#include  "vector2.h"

class collider2d
{
public:
	collider2d() = default;
	explicit collider2d(const vector2& scale);

	bool check_collisions(const collider2d& other) const;

	void move(const vector2& position);

private:

	vector2 position_ = vector2(0.0f, 0.0f);
	vector2 scale_ = vector2(1.0f, 1.0f);
};
