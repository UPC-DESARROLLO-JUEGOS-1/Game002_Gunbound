#pragma once

#include <stdlib.h>

class RandomGenerator
{
private:
	RandomGenerator() {}

public:
	static int RandomInt(int n1, int n2)
	{
		return n1 + rand() % (n2 - n1 + 1);
	}
};