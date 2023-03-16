#pragma once

#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Random.h"
#include "Color.h"
#include "Vector.h"

class Cube
{
	private:

		const unsigned char _colorChange = 10;

		float _scale = 1;
		float _speed = 1;
		Vector3 _position;
		Color _color;

	public:
		Cube();

		void SetPosition(Vector3 position);

		void DrawCube();
};

