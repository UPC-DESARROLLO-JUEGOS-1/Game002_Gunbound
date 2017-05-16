#pragma once

#include "NDrawable2D.h"

class NPrimitiveQuad : public NDrawable2D
{
public:
	NPrimitiveQuad() {}
	~NPrimitiveQuad() {
		NDrawable2D::~NDrawable2D();
	}

	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
	int GetVisibleWidth() { return mWidth * mScaleX; }
	int GetVisibleHeight() { return mHeight * mScaleY; }

	void Initialize(float x, float y, int width, int height, 
		GLubyte r, GLubyte g, GLubyte b, GLubyte a);
	void Draw(float dt);

protected:
	int mWidth;
	int mHeight;
};

