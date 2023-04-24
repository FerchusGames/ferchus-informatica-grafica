#pragma once
#include "game_object2d.h"

#include "plane.h"
#include "collider2d.h"

class block : public game_object2d
{
public:

	block();
	~block() override = default;
	explicit block(const vector2& position);
	explicit block(const vector2& position, const vector2& scale);

	void draw() override;
	void update() override;

	static int get_count();

private:

	plane plane_ = plane(180, color::green);
	collider2d collider_ = collider2d(scale_);

	static int count_;
};

