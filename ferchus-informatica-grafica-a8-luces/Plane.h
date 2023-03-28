#pragma once

#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Vector2.h";

class Plane
{
public:
	Plane();
	Plane(int horizontalQuadCount);

	void Draw();

private:
	int _horizontalQuadCount = 10;
};

