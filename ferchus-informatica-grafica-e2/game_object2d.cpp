#include "game_object2d.h"

game_object2d::game_object2d(const vector2& position, const vector2& scale)
{
	position_ = position;
	scale_ = scale;
}

void game_object2d::set_position(const vector2& position)
{
	position_ = position;
}

void game_object2d::set_scale(const vector2& scale)
{
	scale_ = scale;
}
