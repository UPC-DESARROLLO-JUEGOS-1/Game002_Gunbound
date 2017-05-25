#include "GPlayerControl.h"
//#include "GunboundGameApp.h"
#include "GPlayer.h"

GPlayerControl::GPlayerControl(GPlayer* player)
{
	mPlayer = player;
}

GPlayerControl::~GPlayerControl()
{
}

void GPlayerControl::Initialize() {
	//GunboundGameApp::GET_GAMEAPP()->GetEngine()->;
}

void GPlayerControl::OnKeyDown(SDL_Keycode key) {
	switch (key)
	{
	case SDLK_LEFT:
		mIsLeft = true;
		break;
	case SDLK_RIGHT:
		mIsRight = true;
		break;
	case SDLK_UP:
		mIsUp = true;
		break;
	case SDLK_DOWN:
		mIsDown = true;
		break;
	case SDLK_SPACE:
		mIsSpacePressed = true;
		break;
	}
}

void GPlayerControl::OnKeyUp(SDL_Keycode key) {
	switch (key)
	{
	case SDLK_LEFT:
		mIsLeft = false;
		break;
	case SDLK_RIGHT:
		mIsRight = false;
		break;
	case SDLK_UP:
		mIsUp = false;
		break;
	case SDLK_DOWN:
		mIsDown = false;
		break;
	case SDLK_SPACE:
		mIsSpacePressed = false;
		mAlreadyShot = false;
		break;
	}
}

void GPlayerControl::Update(float dt)
{
	//SetSpeed(0, 0);
	//if (isLeft && !isRight) SetSpeed(-moveSpeed, 0);
	//if (isRight && !isLeft) SetSpeed(moveSpeed, 0);
}
