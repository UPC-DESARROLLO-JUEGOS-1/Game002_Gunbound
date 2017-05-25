#pragma once

#include <SDL\SDL.h>

class GPlayerControl
{
public:
	GPlayerControl();
	~GPlayerControl();

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	void Initialize();
	void Update(float dt);

private:
	bool mIsRight, mIsLeft, mIsUp, mIsDown, mIsSpacePressed;
	bool mChargingShot;
	bool mAlreadyShot;
	float mCurrentCharge;
};

