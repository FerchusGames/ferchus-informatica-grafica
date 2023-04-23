#include "random.h"

#include <cstdlib>
#include <iostream>

using namespace std;

unsigned char random_u_char()
{
	return rand() % 256;
}

int random_int(const int& min, const int& max) 
{
	int number = max - min + 1;
	number = rand() % number;
	number += min;

	return number;
}

float random_percentage()
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}