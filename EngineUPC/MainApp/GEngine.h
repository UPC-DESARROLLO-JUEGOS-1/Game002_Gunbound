#pragma once

#include "GPlayer.h"
#include "GLogicCamera.h"

#include <SDL\SDL.h>

class GEngine
{
public:
	GEngine();
	~GEngine();

	GPlayer* GetPlayer() { return mPlayer; }
	GLogicCamera* GetLogicCamera() { return mLogicCamera; }

	void Initialize();
	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);
	void Update(float dt);
	void Draw(float dt);

private:
	GPlayer* mPlayer;
	GLogicCamera* mLogicCamera;
};

