#include "Pyramid.h"

Pyramid::Pyramid()
{

	setValues();
	setInitialRotation();
	setRotationAxis();
	normalizeVector(_directionX, _directionY, _directionZ);
}

void Pyramid::setValues()
{
	_colorR = randomPercentage() / 2;
	_colorG = randomPercentage() / 2;
	_colorB = randomPercentage() / 2;

	_directionX = randomPercentage() * randomSign();
	_directionY = randomPercentage() * randomSign();
	_directionZ = randomPercentage() * randomSign();

	_positionX = randomPercentage() * randomSign() * CUBE_HITBOX / 2;
	_positionY = randomPercentage() * randomSign() * CUBE_HITBOX / 2;
	_positionZ = randomPercentage() * randomSign() * CUBE_HITBOX / 2;

	_scale = randomPercentage() * MAX_SCALE + 0.3;

	if (_scale > MAX_SCALE)
	{
		_scale = MAX_SCALE;
	}

	_rotationAxis = rand() % 3;
}

void Pyramid::changeDirection()
{
	_directionX = randomPercentage() * randomSign();
	_directionY = randomPercentage() * randomSign();
	_directionZ = randomPercentage() * randomSign();

	normalizeVector(_directionX, _directionY, _directionZ);
}

void Pyramid::normalizeVector(float& x, float& y, float& z)
{
	// Calculate magnitude
	float magnitude = std::sqrt(x * x + y * y + z * z);

	// Normalize values
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

void Pyramid::setInitialRotation()
{
	_initialRotation = randomPercentage() * 360;
}

void Pyramid::setRotationAxis()
{
	switch (_rotationAxis)
	{
	case 0:
		_rotationX = 1;
		break;
	case 1:
		_rotationY = 1;
		break;
	case 2:
		_rotationZ = 1;
		break;
	}
}

float Pyramid::randomPercentage()
{
	// Create a random number generator engine and seed it with the current time
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());

	// Create a uniform distribution of floats between 0 and 1
	uniform_real_distribution<float> distribution(0.0, 1.0);

	// Generate a random float
	float randomNumber = distribution(generator);

	return randomNumber;
}

int Pyramid::randomSign()
{
	int number = rand() % 2;

	switch (number)
	{
	case 0:
		return -1;
		break;
	case 1:
		return 1;
		break;
	}
}

void Pyramid::drawPyramid()
{
	glBegin(GL_QUADS);

		glColor3f(_colorR, _colorG, _colorB);

		glVertex3f(-1, 0, 1);
		glVertex3f(1, 0, 1);
		glVertex3f(1, 0, -1);
		glVertex3f(-1, 0, -1);

	glEnd();

	glBegin(GL_TRIANGLES);

		float newColorR = _colorR, newColorG = _colorG, newColorB = _colorB;

		changeTone(&newColorR);
		changeTone(&newColorG);
		changeTone(&newColorB);

		glColor3f(newColorR, newColorG, newColorB);

		glVertex3f(0, HEIGHT, 0);
		glVertex3f(-1, 0, 1);
		glVertex3f(1, 0, 1);

		changeTone(&newColorR);
		changeTone(&newColorG);
		changeTone(&newColorB);

		glColor3f(newColorR, newColorG, newColorB);

		glVertex3f(0, HEIGHT, 0);
		glVertex3f(1, 0, 1);
		glVertex3f(1, 0, -1);

		changeTone(&newColorR);
		changeTone(&newColorG);
		changeTone(&newColorB);

		glColor3f(newColorR, newColorG, newColorB);

		glVertex3f(0, HEIGHT, 0);
		glVertex3f(1, 0, -1);
		glVertex3f(-1, 0, -1);

		changeTone(&newColorR);
		changeTone(&newColorG);
		changeTone(&newColorB);

		glColor3f(newColorR, newColorG, newColorB);

		glVertex3f(0, HEIGHT, 0);
		glVertex3f(-1, 0, -1);
		glVertex3f(-1, 0, 1);

	glEnd();
}

void Pyramid::changeTone(float* tone)
{
	*tone *= _colorChange;
}