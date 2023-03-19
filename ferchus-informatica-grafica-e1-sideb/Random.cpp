#include "Random.h"

unsigned char RandomUChar()
{
	return rand() % 256;
}

float RandomPercentage()
{
	return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
}