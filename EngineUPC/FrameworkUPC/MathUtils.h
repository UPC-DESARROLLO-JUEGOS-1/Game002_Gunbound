#pragma once

#include <stdlib.h>

class MathUtils
{
private:
	MathUtils() {}

public:
	static float Clamp(float value, float lower, float upper)
	{
		if (value < lower) return lower;
		if (value > upper) return upper;
		return value;
	}

	static int RandomInt(int n1, int n2)
	{
		return n1 + rand() % (n2 - n1 + 1);
	}
};