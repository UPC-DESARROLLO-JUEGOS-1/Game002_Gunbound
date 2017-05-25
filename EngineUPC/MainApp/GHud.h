#pragma once

#include <FrameworkUPC\Quad.h>

class GHud
{
public:
	GHud() {}
	~GHud() {}

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	Quad* GetPlayerChargeBar() { return &mPlayerChargeBar; }

private:
	Quad mPlayerChargeBar;
};

