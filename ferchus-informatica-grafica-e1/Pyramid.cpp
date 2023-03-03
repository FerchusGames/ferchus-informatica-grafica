#include "Pyramid.h"

Pyramid::Pyramid()
{
	setValues();
}

void Pyramid::setValues()
{
	_colorR = getRandomPercentage() / 2;
	_colorG = getRandomPercentage() / 2;
	_colorB = getRandomPercentage() / 2;

	_directionX = getRandomPercentage();
	_directionY = getRandomPercentage();
	_directionZ = getRandomPercentage();

	_scale = getRandomPercentage();

	_rotationAxis = rand() % 3;
}

float Pyramid::getRandomPercentage()
{
	srand(time(0));
	
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

void Pyramid::drawPyramid()
{

}

void Pyramid::changeDirection()
{

}