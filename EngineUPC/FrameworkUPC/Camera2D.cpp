#include "Camera2D.h"

void Camera2D::Initialize(int screenWidth, int screenHeight)
{
	BaseCamera::Initialize(screenWidth, screenHeight);

	projectionMatrix = glm::ortho(0.0f, (float)screenWidth, (float)screenHeight, 0.0f);
}

void Camera2D::Update(float dt)
{
	BaseCamera::Update(dt);
}
