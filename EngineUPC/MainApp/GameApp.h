#pragma once

#include <FrameworkUPC\GameFramework.h>

#include <functional>

class GameApp
{
public:
	GameApp();
	~GameApp();

	static const int WIDTH = 1280;
	static const int HEIGHT = 720;

	void Start();
private:
	GameFramework frameWork;

	void InitializeApp();
	void OnInput(SDL_Event evnt);
	void Update(float dt);
	void Draw(float dt);
};