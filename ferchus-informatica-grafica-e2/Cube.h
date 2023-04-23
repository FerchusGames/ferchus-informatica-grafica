#pragma once

#include "color.h"
#include "vector3.h"

class cube
{
	private:

		unsigned char color_change_ = 10;

		float scale_ = 1.0f;

		vector3 position_;

		color color_;

	public:
		cube();

		void set_position(vector3 position);
		void set_color(color color);
		void set_scale(float scale);

		void draw() const;
};