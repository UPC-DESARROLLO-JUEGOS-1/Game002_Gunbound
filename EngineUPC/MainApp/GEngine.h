#pragma once

#include "GPlayer.h"
#include "GLogicCamera.h"
#include "GWorld.h"
#include "GProjectileManager.h"
#include "GTurnManager.h"

#include <SDL\SDL.h>

class GEngine
{
public:
	GEngine() {}
	~GEngine()
	{
		delete mPlayer;
		delete mPlayer2;
		delete mWorld;
		delete mLogicCamera;
		delete mProjectileManager;
	}

	GWorld* GetWorld() { return mWorld; }
	GPlayer* GetPlayer() { return mPlayer; }
	GPlayer* GetPlayer2() { return mPlayer2; }
	GLogicCamera* GetLogicCamera() { return mLogicCamera; }
	GProjectileManager* GetProjectileManager() { return mProjectileManager; }
	GTurnManager* GetTurnManager() { return mTurnManager; }

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	GPlayer* mPlayer;
	GPlayer* mPlayer2;
	GWorld* mWorld;
	GLogicCamera* mLogicCamera;
	GProjectileManager* mProjectileManager;
	GTurnManager* mTurnManager;
};

