#pragma once

#include "GBaseActor.h"

class GBaseProjectile : public GBaseActor
{
public:
	GBaseProjectile(GEngine* engine) :
		GBaseActor::GBaseActor(engine),
		mTimeParameter(0.0f),
		mPosition0(0, 0),
		mSpeed0(0, 0),
		mGravity(0, 0),
		mWind(0, 0)
	{}
	~GBaseProjectile() {}

	void Initialize(float x, float y, float angle, float strength);
	void Update(float dt);
	void Draw(float dt);

private:
	float mTimeParameter;
	Vector2 mPosition0, mSpeed0;
	Vector2 mGravity;
	Vector2 mWind;
};

