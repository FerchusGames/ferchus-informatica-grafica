#pragma once

class plane
{
public:
	plane() = default;
	explicit plane(const int& _horizontal_quad_count);

	void draw() const;

private:
	int horizontal_quad_count_ = 10;
};

