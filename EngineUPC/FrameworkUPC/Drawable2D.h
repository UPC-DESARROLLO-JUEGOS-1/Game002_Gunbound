#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "BaseShader.h"
#include "BaseCamera.h"
#include "Vector2.h"

class Drawable2D
{
public:
	Drawable2D();
	~Drawable2D();

	virtual Vector2 GetPosition() { return position; }
	virtual Vector2 GetScale() { return scale; }
	virtual float GetRotationZ() { return rotationZ; }

	virtual void SetX(float value)
	{
		position.x = value;
		needMatrixUpdate = true;
	}
	virtual void SetY(float value)
	{
		position.y = value;
		needMatrixUpdate = true;
	}
	virtual void SetScaleX(float value)
	{
		scale.x = value;
		needMatrixUpdate = true;
	}
	virtual void SetScaleY(float value)
	{
		scale.y = value;
		needMatrixUpdate = true;
	}
	virtual void SetRotationZ(float value)
	{
		rotationZ = value;
		needMatrixUpdate = true;
	}

	virtual void Translate(float dx, float dy)
	{
		position.x += dx;
		position.y += dy;
		needMatrixUpdate = true;
	}

	void SetRenderCamera(BaseCamera* renderCamera) { this->renderCamera = renderCamera; }

	void Initialize(float x, float y);

	virtual void Update(float dt)
	{
		if (needMatrixUpdate)
		{
			glm::mat4 result(1.0f);
			glm::vec3 translate(position.x, position.y, 0.0f);
			glm::vec3 scale(scale.x, scale.y, 0.0f);
			glm::vec3 rotation(0.0f, 0.0f, 1.0f);

			result = glm::translate(result, translate);
			result = glm::scale(result, scale);
			result = glm::rotate(result, rotationZ, rotation);

			worldMatrix = result;
			needMatrixUpdate = false;
		}
	}

	virtual void Draw(float dt)
	{

	}

protected:
	Vector2 position;
	Vector2 scale;
	float rotationZ;
	glm::mat4 worldMatrix;
	bool needMatrixUpdate;

	GLuint vbo_ID;
	BaseShader* currentShader;
	BaseCamera* renderCamera;
};