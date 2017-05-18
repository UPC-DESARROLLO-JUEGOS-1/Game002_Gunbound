#pragma once

#include <vector>
#include "Bullet.h"

class GameScene;

class BulletManager
{
public:
	BulletManager() {}
	~BulletManager()
	{
		for each (Bullet* bullet in bulletGroup) { delete bullet; }
	}

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void CreateBullet(Bullet* bulletAux) { bulletGroup.push_back(bulletAux); }
	std::vector<Bullet*>* GetBullets() { return &bulletGroup; }

private:
	std::vector<Bullet*> bulletGroup;
};

