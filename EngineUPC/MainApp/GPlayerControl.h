#pragma once

#include <SDL\SDL.h>

class GPlayer;

class GPlayerControl
{
public:
	GPlayerControl(GPlayer* player);
	~GPlayerControl();

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	void Initialize();
	void Update(float dt);

private:
	GPlayer* mPlayer;
};

