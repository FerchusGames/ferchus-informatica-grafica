#pragma once

#include <cstdlib>

unsigned char RandomUChar()
{
	return rand() % 256;
}

float RandomFloat()
{
	return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
}