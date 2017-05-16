#pragma once

#include "NBaseCamera.h"

class NCamera2D : public NBaseCamera
{
public:
	NCamera2D() { NBaseCamera::NBaseCamera(); }
	~NCamera2D() { NBaseCamera::~NBaseCamera(); }

	void Initialize(int screenWidth, int screenHeight);
	void Update(float dt);
};

