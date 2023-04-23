#pragma once

#include "game_object2d.h"

#include "plane.h"
#include "collider2d.h"

class paddle : public game_object2d
{
public:

	paddle(const vector2& position, const vector2& scale, const float& speed) : game_object2d(position, scale), speed_(speed){}
	~paddle() = default;

	void draw() override;
	void update() override;
	void set_speed(const float& speed);

private:

	plane plane_ = plane(180);
	collider2d collider_ = collider2d(scale_);
	float speed_ = 1.0f;
};
