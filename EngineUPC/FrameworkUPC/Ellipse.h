#pragma once

#include "Drawable2D.h"

class Ellipse : public Drawable2D
{
public:
	Ellipse() {}
	~Ellipse() { Drawable2D::~Drawable2D(); }

	void Initialize(float x, float y, float radius, int vertexCount);
	void Draw(float dt);

private:
	int vertexCount;
	int indicesCount;
	float radius;
	int r, g, b, a;

	GLuint ibo_ID;

	void BindData();
	void BindIndices();
};

