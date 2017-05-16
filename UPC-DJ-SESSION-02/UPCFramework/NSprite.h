#pragma once

#include "NImageContent.h"
#include "NDrawable2D.h

#include <string>

class NSprite : public NDrawable2D
{
public:
	NSprite() {}
	~NSprite() {
		mContent = nullptr;

		NDrawable2D::~NDrawable2D();
	}

	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
	int GetVisibleWidth() { return mWidth * mScaleX; }
	int GetVisibleHeight() { return mHeight * mScaleY; }

	void Initialize(float x, float y, const std::string path);
	void Draw(float dt);

protected:
	int mWidth;
	int mHeight;

	NImageContent* mContent;
};

