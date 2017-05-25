#include "GWorldForces.h"

GWorldForces* GWorldForces::_instance;
GWorldForces* GWorldForces::GET_WORLD_FORCES() { return _instance; }

GWorldForces::GWorldForces() :
	mGravity(0, 150),
	mWind(-100, 0)
{
	GWorldForces::_instance = this;
}

GWorldForces::~GWorldForces()
{
}
