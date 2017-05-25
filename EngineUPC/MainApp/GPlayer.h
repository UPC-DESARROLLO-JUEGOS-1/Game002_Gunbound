#pragma once

#include "GPlayerControl.h"
#include "GBaseActor.h"

#include <string>

class GEngine;

class GPlayer : public GBaseActor
{
public:
	GPlayer(GEngine* engine);
	~GPlayer()
	{
		delete mPlayerControl;
	}

	GPlayerControl* GetControl() { return mPlayerControl; }

	void Initialize(float x, float y, std::string path);
	void Update(float dt);
	void Draw(float dt);

	void Shoot(float angle, float strength);

private:
	GEngine* mEngine;
	GPlayerControl* mPlayerControl;
	Sprite mCannon;
};

