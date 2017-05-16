#pragma once

#include <GL\glew.h>

struct Position
{
	float x;
	float y;
};

struct Color
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};

struct dtPrimitiveVertex {
	Position Position;
	Color Color;

	void SetPosition(float x, float y) {
		Position.x = x;
		Position.y = y;
	}

	void SetColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		Color.r = r;
		Color.g = g;
		Color.b = b;
		Color.a = a;
	}
};