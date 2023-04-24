#pragma once
#include "game_object2d.h"

#include "plane.h"
#include "collider2d.h"
#include "vector2.h"

class ball : public game_object2d
{
public:

	ball();
	~ball() override = default;
	explicit ball(const float& speed);
	explicit ball(const vector2& direction);
	explicit ball(const vector2& direction, const float& speed);

	void change_direction(const bool& horizontal_change);

	void draw() override;
	void update() override;
	void translate();

	float get_speed() const;
	vector2 get_direction() const;
	vector2 get_next_position() const;

	void set_speed(const float& speed);

private:

	plane plane_ = plane(180, color::red);
	collider2d collider_ = collider2d(scale_);
	vector2 direction_ = vector2(0.3f, 1.0f);

	float speed_ = 4.0f;
};

