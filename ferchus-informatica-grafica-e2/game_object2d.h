#pragma once
#include "vector2.h"


class game_object2d
{
public:
	game_object2d() = default;
	game_object2d(const vector2& position, const vector2& scale) : position_(position), scale_(scale) {}

	virtual ~game_object2d() = default;
	virtual void draw() = 0;
	virtual void update() = 0;

	void set_position(const vector2& position);
	void set_scale(const vector2& scale);

protected:
	vector2 position_ = vector2(0.0f, 0.0f);
	vector2 scale_ = vector2(1.0f, 1.0f);
};
