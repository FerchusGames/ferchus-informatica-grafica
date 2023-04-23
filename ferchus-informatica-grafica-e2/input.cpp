#include "input.h"

#include <algorithm>

float input::horizontal_axis_ = 0.0f;
float input::vertical_axis_ = 0.0f;

float input::get_horizontal_axis()
{
	return horizontal_axis_;
}

float input::get_vertical_axis()
{
	return vertical_axis_;
}

void input::set_horizontal_axis(const float& horizontal_axis)
{
	horizontal_axis_ = horizontal_axis;
}

void input::set_vertical_axis(const float& vertical_axis)
{
	vertical_axis_ = vertical_axis;
}
