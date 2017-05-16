#pragma once

#include <GL/glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "NBaseShader.h"
#include "NBaseCamera.h"
#include "NColor.h"

class NDrawable2D
{
public:
	NDrawable2D();
	~NDrawable2D();

	virtual float GetX() { return mX; }
	virtual float GetY() { return mY; }
	virtual float GetScaleX() { return mScaleX; }
	virtual float GetScaleY() { return mScaleY; }
	virtual float GetRotationZ() { return mRotationZ; }

	virtual void SetX(float value) {
		mX = value;
		mNeedMatrixUpdate = true;
	}

	virtual void SetY(float value) {
		mY = value;
		mNeedMatrixUpdate = true;
	}

	virtual void SetScaleX(float value) {
		mScaleX = value;
		mNeedMatrixUpdate = true;
	}

	virtual void SetScaleY(float value) {
		mScaleY = value;
		mNeedMatrixUpdate = true;
	}

	virtual void SetRotationZ(float value) {
		mRotationZ = value;
		mNeedMatrixUpdate = true;
	}

	void SetRenderCamera(NBaseCamera* renderCamera) {
		mRenderCamera = renderCamera;
	}

	virtual void SetColor(NColor color) {}

	virtual void Initialize(float x, float y);

	virtual void Update(float dt) {
		if (mNeedMatrixUpdate) {
			glm::mat4 result(1.0f);

			glm::vec3 translate(mX, mY, 0.0f);
			glm::vec3 scale(mScaleX, mScaleY, 1.0f);

			result = glm::translate(result, translate);
			result = glm::scale(result, scale);
			result = glm::rotate(result, mRotationZ, glm::vec3(0.0f, 0.0f, 1.0f));

			mWorldMatrix = result;
			mNeedMatrixUpdate = false;
		}
	}

	virtual void Draw(float dt) {}

protected:
	float mX, mY;
	float mScaleX, mScaleY;
	float mRotationZ;
	glm::mat4 mWorldMatrix;

	GLuint mVBO_ID;
	NBaseShader* mCurrentShader;
	NBaseCamera* mRenderCamera;

private:
	bool mNeedMatrixUpdate;
};

