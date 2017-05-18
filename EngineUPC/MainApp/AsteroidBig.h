#pragma once

#include "Asteroid.h"

class AsteroidBig : public Asteroid
{
public:
	AsteroidBig(BaseScene* scene) :
		Asteroid::Asteroid(scene)
	{}
	~AsteroidBig() {}

	void Initialize();
};

