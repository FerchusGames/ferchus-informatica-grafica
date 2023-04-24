#include "game_object2d.h"

void game_object2d::set_position(const vector2& position)
{
	position_ = position;
}

void game_object2d::set_scale(const vector2& scale)
{
	scale_ = scale;
}

void game_object2d::set_enabled(bool is_enabled)
{
	is_enabled_ = is_enabled;
}

vector2 game_object2d::get_position() const
{
	return position_;
}

vector2 game_object2d::get_scale() const
{
	return scale_;
}
