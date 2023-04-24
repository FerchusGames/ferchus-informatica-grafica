#pragma once

#include "game_object2d.h"

#include "plane.h"
#include "collider2d.h"
#include "color.h"

class paddle : public game_object2d
{
public:

	paddle();
	~paddle() override = default;
	explicit paddle(const vector2& position);
	explicit paddle(const vector2& position, const float& speed);
	explicit paddle(const vector2& position, const vector2& scale);
	explicit paddle(const vector2& position, const vector2& scale, const float& speed);

	void draw() override;
	void update() override;
	void translate();
	void set_speed(const float& speed);

private:

	plane plane_ = plane(180, color::cyan);
	collider2d collider_ = collider2d(scale_);
	float speed_ = 1.0f;
	float movement_limit_ = 3.3f;
};
