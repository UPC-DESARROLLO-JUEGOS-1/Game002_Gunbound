#pragma once

#include <math.h>

class NVector2
{
public:
	NVector2(float x, float y) {
		this->X = x;
		this->Y = y;
	}
	~NVector2() {}

	float X, Y;

	float Length() {
		return sqrtf(X * X + Y * Y);
	}

	NVector2 Direction(NVector2 other) {
		float lenght = Length();

		NVector2* result = new NVector2(0, 0);
		result->X = (other.X - X) / lenght;
		result->Y = (other.Y - Y) / lenght;

		return *result;
	}

	NVector2 Normalize() {
		float length = Length();
		return NVector2(X / length, Y / length);
	}

	//NVector2 Normalize(float magnitude);
};

