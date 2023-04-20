#include "Random.h"

unsigned char RandomUChar()
{
	return rand() % 256;
}

int RandomInt(int min, int max)
{
	int number = max - min + 1;
	number = rand() % number;
	number += min;

	return number;
}

float RandomPercentage()
{
	return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
}