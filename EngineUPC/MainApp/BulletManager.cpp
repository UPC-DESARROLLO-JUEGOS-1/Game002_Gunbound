#include "BulletManager.h"
#include "GameScene.h"

void BulletManager::Initialize()
{
	bulletGroup = std::vector<Bullet*>();
}

void BulletManager::Update(float dt)
{
	for (std::vector<Bullet*>::iterator it = bulletGroup.begin(); it != bulletGroup.end();)
	{
		if (!(*it)->IsAlive())
		{
			delete (*it);
			it = bulletGroup.erase(it);
		}
		else
		{
			(*it)->Update(dt);
			it++;
		}
	}
}

void BulletManager::Draw(float dt)
{
	for (std::vector<Bullet*>::iterator it = bulletGroup.begin(); it != bulletGroup.end(); it++) { (*it)->Draw(dt); }
}
