#pragma once

#include <GL\eglew.h>

struct NColor
{
	GLubyte R;
	GLubyte G;
	GLubyte B;
	GLubyte A;

	static NColor White;

	NColor static CreateColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		NColor color;
		color.R = r;
		color.G = g;
		color.B = b;
		color.A = a;
		
		return color;
	}
}; 

NColor NColor::White = NColor::CreateColor(255, 255, 255, 255);