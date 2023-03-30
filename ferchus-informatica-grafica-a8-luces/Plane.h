#pragma once

#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "Vector2.h";

using namespace std;

class Plane
{
public:
	Plane();
	Plane(int horizontalQuadCount);

	void Draw();

private:
	int _horizontalQuadCount = 10;
};

