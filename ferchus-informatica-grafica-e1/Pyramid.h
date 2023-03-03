#pragma once

#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include <ctime>

class Pyramid
{
private:
	float _scale;
	int _rotationAxis;
	float _colorR, _colorG, _colorB;
	float _directionX, _directionY, _directionZ;
	
	float getRandomPercentage();
	void setValues();

public:
	Pyramid();

	void drawPyramid();
	void changeDirection();
};



