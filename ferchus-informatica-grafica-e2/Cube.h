#pragma once

#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Random.h"
#include "color.h"
#include "vector3.h"
#include <iostream>

class Cube
{
	private:

		unsigned char _colorChange = 10;

		float _scale = 1;
		float _scaleMultiplier = 1;
		float _scalePercentage = 1;
		float _minScalePercentage = 0.3f;

		float _speed = 1;
		float _speedMultiplier = 1;
		float _speedPercentage = 1;
		float _minSpeedPercentage = 0.5f;
		float _movementRange = 0.3;

		vector3 _position;

		color _color;

	public:
		Cube();

		void SetPosition(vector3 position);
		void SetColor(color color);
		void SetScale(float scale);

		void Draw();

		void MoveBackAndForth(float deltaTime);
};