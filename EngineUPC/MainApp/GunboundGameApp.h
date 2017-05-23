#pragma once

#include <SDL\SDL.h>
#include "GEngine.h"

class GunboundGameApp
{
public:
	static GunboundGameApp* GET_GAMEAPP();

	GunboundGameApp();
	~GunboundGameApp();

	GEngine* GetEngine() { return mEngine; }

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	static GunboundGameApp* GAMEAPP;

	GEngine* mEngine;
};