#pragma once

#include "Drawable2D.h"

class Circle : public Drawable2D
{
public:
	Circle() {}
	~Circle()
	{
		Drawable2D::~Drawable2D();
	}

	void Initialize(float x, float y, int radius);
	void Draw(float dt);

	void SetColor(float r, float g, float b, float a);

protected:
	int radius, angles;
	int r, g, b, a;

	void BindData();
};

