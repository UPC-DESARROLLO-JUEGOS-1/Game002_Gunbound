#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>

class NBaseCamera {

public:
	NBaseCamera() :
		mResultMatrix(1.0f),
		mWorldMatrix(1.0f),
		mViewMatrix(1.0f),
		mProjectionMatrix(1.0f),
		mNeedMatrixUpdate(true),
		mX(0), mY(0), mZ(0),
		mScaleX(1), mScaleY(1), mScaleZ(1),
		mRotationX(0), mRotationY(0), mRotationZ(0)
	{}

	~NBaseCamera() {}

	void SetX(float value) {
		if (mX != value) {
			mX = value;

			float* worldMatrixPtr = glm::value_ptr(mWorldMatrix);
			*(worldMatrixPtr + 12) = value; // position: 12 que seria: M41

			mNeedMatrixUpdate = true;
		}
	}

	void SetY(float value) {
		if (mY != value) {
			mY = value;

			float* worldMatrixPtr = glm::value_ptr(mWorldMatrix);
			*(worldMatrixPtr + 13) = value; // position: 13 que seria: M42

			mNeedMatrixUpdate = true;
		}
	}

	void SetZ(float value) {
		if (mZ != value) {
			mZ = value;

			float* worldMatrixPtr = glm::value_ptr(mWorldMatrix);
			*(worldMatrixPtr + 14) = value; // position: 14 que seria: M43

			mNeedMatrixUpdate = true;
		}
	}

	void SetScaleX(float value) {
		if (mScaleX != value) {
			mScaleX = value;

			float* worldMatrixPtr = glm::value_ptr(mWorldMatrix);
			*(worldMatrixPtr + 0) = value; // position: 0 que seria: M11

			mNeedMatrixUpdate = true;
		}
	}

	void SetScaleY(float value) {
		if (mScaleY != value) {
			mScaleY = value;

			float* worldMatrixPtr = glm::value_ptr(mWorldMatrix);
			*(worldMatrixPtr + 5) = value; // position: 5 que seria: M22

			mNeedMatrixUpdate = true;
		}
	}

	void SetScaleZ(float value) {
		if (mScaleZ != value) {
			mScaleZ = value;

			float* worldMatrixPtr = glm::value_ptr(mWorldMatrix);
			*(worldMatrixPtr + 10) = value; // position: 10 que seria: M33

			mNeedMatrixUpdate = true;
		}
	}

	float GetX() { return mX; }
	float GetY() { return mY; }
	float GetZ() { return mZ; }
	float GetScaleX() { return mScaleX; }
	float GetScaleY() { return mScaleY; }
	float GetScaleZ() { return mScaleZ; }
	float GetRotationX() { return mRotationX; }
	float GetRotationY() { return mRotationY; }
	float GetRotationZ() { return mRotationZ; }
	glm::mat4 GetResultMatrix() { return mResultMatrix; }

	virtual void Initialize(int screenWidth, int screenHeight) {
		mScreenWidth = screenWidth;
		mScreenHeight = screenHeight;
	}

	virtual void Update(float dt) {
		if (mNeedMatrixUpdate) {
			mResultMatrix = (mWorldMatrix * mViewMatrix) * mProjectionMatrix;
			mNeedMatrixUpdate = false;
		}
	}

protected:
	int mScreenWidth, mScreenHeight;
	bool mNeedMatrixUpdate;

	glm::mat4 mResultMatrix;
	glm::mat4 mWorldMatrix;
	glm::mat4 mViewMatrix;
	glm::mat4 mProjectionMatrix;

	float mX, mY, mZ;
	float mScaleX, mScaleY, mScaleZ;
	float mRotationX, mRotationY, mRotationZ;
};