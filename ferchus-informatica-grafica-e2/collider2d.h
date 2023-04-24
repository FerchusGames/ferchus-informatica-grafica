#pragma once

#include  "vector2.h"
#include <vector>

class collider2d
{
public:
	collider2d() = default;
	explicit collider2d(const vector2& scale);

	bool check_collisions() const;
	bool check_collisions(const vector2& next_position) const;

	bool is_colliding(const collider2d* collider) const;
	bool is_colliding(const vector2& position, const collider2d* collider) const;

	void translate(const vector2& position);

private:

	static std::vector<collider2d*> colliders_;

	vector2 position_ = vector2(0.0f, 0.0f);
	vector2 scale_ = vector2(1.0f, 1.0f);
};
