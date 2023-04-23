#pragma once
class input
{
public:

	virtual ~input() = 0;

	static float get_horizontal_axis();
	static float get_vertical_axis();
	static void set_horizontal_axis(const float& horizontal_axis);
	static void set_vertical_axis(const float& vertical_axis);

private:
	static float horizontal_axis_;
	static float vertical_axis_;
};

