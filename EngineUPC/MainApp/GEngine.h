#pragma once

#include "GPlayer.h"
#include "GLogicCamera.h"
#include "GWorld.h"
#include "GProjectileManager.h"

#include <SDL\SDL.h>

class GEngine
{
public:
	GEngine() {}
	~GEngine()
	{
		delete mPlayer;
		delete mWorld;
		delete mLogicCamera;
		delete mProjectileManager;
	}

	GWorld* GetWorld() { return mWorld; }
	GPlayer* GetPlayer() { return mPlayer; }
	GLogicCamera* GetLogicCamera() { return mLogicCamera; }

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	void OnPlayerShot(GBaseProjectile* newProjectile);

private:
	GPlayer* mPlayer;
	GWorld* mWorld;
	GLogicCamera* mLogicCamera;
	GProjectileManager* mProjectileManager;
};

