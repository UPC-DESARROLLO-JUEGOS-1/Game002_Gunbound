#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>

class BaseCamera
{
public:
	BaseCamera() :
		resultMatrix(1.0f),
		worldMatrix(1.0f),
		viewMatrix(1.0f),
		projectionMatrix(1.0f),
		needMatrixUpdate(true),
		x(0), y(0), z(0),
		scaleX(1), scaleY(1), scaleZ(1),
		rotationX(0), rotationY(0), rotationZ(0)
	{}
	~BaseCamera() {}

	void SetX(float value)
	{
		if (x != value)
		{
			x = value;
			float* worldMatrixPtr = glm::value_ptr(worldMatrix);
			*(worldMatrixPtr + 12) = value;
			needMatrixUpdate = true;
		}
	}

	void SetY(float value)
	{
		if (y != value)
		{
			y = value;
			float* worldMatrixPtr = glm::value_ptr(worldMatrix);
			*(worldMatrixPtr + 13) = value;
			needMatrixUpdate = true;
		}
	}

	void SetZ(float value)
	{
		if (z != value)
		{
			z = value;
			float* worldMatrixPtr = glm::value_ptr(worldMatrix);
			*(worldMatrixPtr + 14) = value;
			needMatrixUpdate = true;
		}
	}

	void SetScaleX(float value)
	{
		if (scaleX != value)
		{
			scaleX = value;
			float* worldMatrixPtr = glm::value_ptr(worldMatrix);
			*(worldMatrixPtr + 0) = value;
			needMatrixUpdate = true;
		}
	}

	void SetScaleY(float value)
	{
		if (scaleY != value)
		{
			scaleY = value;
			float* worldMatrixPtr = glm::value_ptr(worldMatrix);
			*(worldMatrixPtr + 5) = value;
			needMatrixUpdate = true;
		}
	}

	void SetScaleZ(float value)
	{
		if (scaleZ != value)
		{
			scaleZ = value;
			float* worldMatrixPtr = glm::value_ptr(worldMatrix);
			*(worldMatrixPtr + 10) = value;
			needMatrixUpdate = true;
		}
	}

	float GetX() { return x; }
	float GetY() { return x; }
	float GetZ() { return x; }
	float GetScaleX() { return scaleX; }
	float GetScaleY() { return scaleY; }
	float GetScaleZ() { return scaleZ; }
	float GetRotationX() { return rotationX; }
	float GetRotationY() { return rotationY; }
	float GetRotationZ() { return rotationZ; }
	glm::mat4 GetResultMatrix() { return resultMatrix; }

	virtual void Initialize(int screenWidth, int screenHeight)
	{
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
	}

	virtual void Update(float dt)
	{
		if (needMatrixUpdate)
		{
			resultMatrix = (worldMatrix*viewMatrix)*projectionMatrix;
			needMatrixUpdate = false;
		}
	}


protected:
	int screenWidth, screenHeight;
	bool needMatrixUpdate;

	glm::mat4 resultMatrix;
	glm::mat4 worldMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	float x, y, z;
	float scaleX, scaleY, scaleZ;
	float rotationX, rotationY, rotationZ; //radians
};