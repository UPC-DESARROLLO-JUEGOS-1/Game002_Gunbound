#include "NDrawable2D.h"

NDrawable2D::NDrawable2D(): 
	mVBO_ID(0),
	mNeedMatrixUpdate(true),
	mWorldMatrix(1.0f),
	mX(0.0f), mY(0.0f),
	mScaleX(1.0f), mScaleY(1.0f),
	mRotationZ(0.0f)
{ }

NDrawable2D::~NDrawable2D()
{
	delete mCurrentShader;
	mRenderCamera = nullptr;

	if (mVBO_ID != 0) {
		glDeleteBuffers(1, &mVBO_ID);
	}
}

void NDrawable2D::Initialize(float x, float y) {
	mX = x;
	mY = y;

	if (mVBO_ID == 0) {
		glGenBuffers(1, &mVBO_ID);
	}
}
