#pragma once

#include <math.h>

class Vector2
{
public:
	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	~Vector2() {}

	float x, y;
	float Magnitude()
	{
		return sqrtf(x*x + y*y);
	}

	Vector2 Direction(Vector2 other)
	{
		float magnitude = Magnitude();
		Vector2* result = new Vector2(0, 0);
		result->x = (other.x - x) / magnitude;
		result->y = (other.y - y) / magnitude;
		return *result;
	}

	Vector2 Normalize()
	{
		float magnitude = Magnitude();
		return Vector2(x / magnitude, y / magnitude);
	}

	Vector2 Normalize(float magnitude) {}
};

