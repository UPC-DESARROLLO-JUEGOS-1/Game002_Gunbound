#pragma once

#include <SDL\SDL.h>
#include <FrameworkUPC\Sprite.h>
#include <FrameworkUPC\Quad.h>
#include "GWorld.h"

class GPlayer;

class GPlayerControl
{
public:
	GPlayerControl(GPlayer* player, GEngine* engine);
	~GPlayerControl();

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	void Initialize(Sprite* playerBody, Sprite* cannonBody);
	void Update(float dt);

	void SetInactive()
	{
		mIsRight = mIsLeft = mIsUp = mIsDown = mIsSpacePressed = false;
		mAlreadyShot = mChargingShot = false;
	}

private:
	GEngine* mEngine;
	bool mIsRight, mIsLeft, mIsUp, mIsDown, mIsSpacePressed;

	float mMoveSpeed;
	short mDirection;
	float mCurrentAngle;
	float mAngleChangeSpeed;

	float mMaxStrength;
	bool mChargingShot;
	bool mAlreadyShot;
	float mCurrentCharge;

	GPlayer* mPlayer;
	Sprite* mPlayerBody;
	Sprite* mCannonBody;
	Quad* mStrengthChargeBar;

	GWorld* mWorld;

	void ChargeShot();
	void Shoot();
};

