#pragma once

#include "NDrawable2D.h"

class NPrimitiveCircumference : public NDrawable2D
{
public:
	NPrimitiveCircumference() { }
	~NPrimitiveCircumference() { NDrawable2D::~NDrawable2D(); }

	void Initialize(float x, float y, float radius, int vertexCount);
	void Draw(float dt);

private:
	int mVertexCount;
	int mIndicesCount;
	float mRadius;

	GLuint mIBO_ID;
};

