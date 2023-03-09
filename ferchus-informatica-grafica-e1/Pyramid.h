#pragma once

#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <ctime>
#include <random>
#include <cmath>
#include "SceneConstants.h"

using namespace std;

class Pyramid
{
private:
	int _rotationAxis;
	float _colorR, _colorG, _colorB;

	float _colorChange = 1.1;
	
	const float HEIGHT = 1.8;
	const float HALF_HEIGHT = HEIGHT / 2;
	const float MAX_SCALE = 1.5;

	float randomPercentage();
	int randomSign();

	void changeTone(float* tone);
	void setValues();
	void setInitialRotation();
	void setRotationAxis();
	void normalizeVector(float& x, float& y, float& z);

public:
	Pyramid();

	void drawPyramid();

	float _scale;
	float _initialRotation;
	float _directionX, _directionY, _directionZ;
	float _positionX, _positionY, _positionZ;
	float _rotationX = 0.0f, _rotationY = 0.0f, _rotationZ = 0.0f;
};



