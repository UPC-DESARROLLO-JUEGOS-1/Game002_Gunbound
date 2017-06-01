#pragma once

#include "Drawable2D.h"

class Quad : public Drawable2D
{
public:
	Quad() {}
	~Quad() {}

	int GetWidth() { return width; }
	int GetHeight() { return height; }
	int GetVisibleWidth() { return width*abs(scale.x); }
	int GetVisibleHeight() { return height*abs(scale.y); }

	void Initialize(float x, float y, int width, int height);
	void Update(float dt);
	void Draw(float dt);

	void SetColor(float r, float g, float b, float a);

protected:
	int width, height;
	int r, g, b, a;

	void BindData();
};

