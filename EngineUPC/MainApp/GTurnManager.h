#pragma once

#include "GPlayer.h"

class GEngine;

class GTurnManager
{
public:
	GTurnManager(GEngine* engine) :
		mEngine(engine)
	{}
	~GTurnManager() {}

	void Initialize();
	void Update(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	GEngine* mEngine;

	int mActivePlayerIndex;
	GPlayer* mActivePlayer;

	void ChangeActivePlayer();
};

