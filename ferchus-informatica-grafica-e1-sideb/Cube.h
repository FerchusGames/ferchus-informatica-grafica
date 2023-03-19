#pragma once

#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Random.h"
#include "Color.h"
#include "Vector.h"

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

		Vector3 _position;

		Color _color;


	public:
		Cube();

		void SetPosition(Vector3 position);

		void Draw(float time);
};