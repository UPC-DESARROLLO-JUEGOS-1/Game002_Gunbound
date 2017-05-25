#pragma once

#include <SDL\SDL.h>
#include "GEngine.h"
#include "GHud.h"

class GunboundGameApp
{
public:
	static GunboundGameApp* GET_GAMEAPP();

	GunboundGameApp();
	~GunboundGameApp()
	{
		delete mEngine;
		delete mHud;
	}

	GEngine* GetEngine() { return mEngine; }
	GHud* GetHud() { return mHud; }

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	static GunboundGameApp* GAMEAPP;

	GEngine* mEngine;
	GHud* mHud;
};