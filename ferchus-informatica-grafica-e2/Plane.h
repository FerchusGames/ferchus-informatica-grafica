#pragma once

#include "vector2.h"
#include "color.h"

class plane
{
public:
	plane() = default;
	explicit plane(const int& horizontal_quad_count);
	explicit plane(const int& horizontal_quad_count, const color& color);
	explicit plane(const vector2& position);
	explicit plane(const vector2& position, const color& color);
	explicit plane(const vector2& position, const int& horizontal_quad_count);
	explicit plane(const vector2& position, const vector2& scale);
	explicit plane(const vector2& position, const vector2& scale, const color& color);
	explicit plane(const vector2& position, const vector2& scale, const int& horizontal_quad_count);

	void draw() const;

private:

	vector2 position_ = vector2(0.0f, 0.0f);
	vector2 scale_ = vector2(1.0f, 1.0f);
	color color_ = color(1.0f, 1.0f, 1.0f);

	int horizontal_quad_count_ = 10;
};

