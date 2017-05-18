#pragma once

#include <FrameworkUPC\Sprite.h>

class GameUI
{
public:
	GameUI() {}
	~GameUI()
	{
		for each (Sprite* life in playerLives) { delete life; }
		for each (Sprite* ammo in playerAmmo) { delete ammo; }
	}

	void Initialize(int lives, int ammo);
	void Update(float dt);
	void Draw(float dt, int lives, int ammo);

private:
	int maxLives, maxAmmo;

	std::vector<Sprite*> playerLives;
	std::vector<Sprite*> playerAmmo;
};

