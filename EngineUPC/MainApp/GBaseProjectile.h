#pragma once

#include "GBaseActor.h"

class GWorld;
class GEngine;
class GLogicCamera;

class GBaseProjectile : public GBaseActor
{
public:
	GBaseProjectile(GEngine* engine);
	~GBaseProjectile();

	void Initialize(float x, float y, float angle, float strength);
	void Update(float dt);
	void Draw(float dt);

protected:
	float mTimeParameter;
	int mPower;
	Vector2 mPosition0, mSpeed0;
	Vector2 mGravity;
	Vector2 mWind;

	GWorld* mWorld;
	GEngine* mEngine;
	GLogicCamera* mLogicCamera;
};

