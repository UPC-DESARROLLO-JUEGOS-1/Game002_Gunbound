#pragma once

#include <FrameworkUPC\Vector2.h>

class GWorldForces
{
public:
	static GWorldForces* GET_WORLD_FORCES();
	GWorldForces();
	~GWorldForces();

	Vector2 GetGravity() { return mGravity; }
	Vector2 GetWind() { return mWind; }

private:
	static GWorldForces* _instance;
	Vector2 mGravity;
	Vector2 mWind;
};

