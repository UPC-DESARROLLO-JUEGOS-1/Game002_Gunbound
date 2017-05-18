#pragma once

#include "BaseCamera.h"

class Camera2D : public BaseCamera
{
public:
	Camera2D() { BaseCamera::BaseCamera(); }
	~Camera2D() { BaseCamera::~BaseCamera(); }

	void Initialize(int screenWidth, int screenHeight);
	void Update(float dt);
};

