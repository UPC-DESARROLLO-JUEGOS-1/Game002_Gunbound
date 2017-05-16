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

struct UV {
	float u;
	float v;
};

struct dtSpriteVertex {
	Position Position;
	Color Color;
	UV UV;

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

	void SetUV(float u, float v) {
		UV.u = u;
		UV.v = v;
	}
};