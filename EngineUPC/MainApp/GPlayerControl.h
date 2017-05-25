#pragma once

#include <SDL\SDL.h>
#include <FrameworkUPC\Sprite.h>
#include <FrameworkUPC\Quad.h>

class GPlayer;

class GPlayerControl
{
public:
	GPlayerControl(GPlayer* player);
	~GPlayerControl();

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	void Initialize(Sprite* playerBody, Sprite* cannonBody);
	void Update(float dt);

private:

	bool mIsRight, mIsLeft, mIsUp, mIsDown, mIsSpacePressed;

	float mMoveSpeed;
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

	void ChargeShot();
	void Shoot();
};

