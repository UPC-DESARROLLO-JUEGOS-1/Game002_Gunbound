#pragma once

#include "GPlayerControl.h"
#include "GBaseActor.h"

#include <string>

class GPlayer : public GBaseActor
{
public:
	GPlayer();
	~GPlayer();

	GPlayerControl* GetControl() { return &mPlayerControl; }

	void Initialize(float x, float y, std::string path);
	void Update(float dt);
	void Draw(float dt);

private:
	GPlayerControl mPlayerControl;
};

