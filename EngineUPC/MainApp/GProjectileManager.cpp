#include "GProjectileManager.h"
#include "GameScene.h"

void GProjectileManager::Initialize()
{
	mProjectileGroup = std::vector<GBaseProjectile*>();
}

void GProjectileManager::Update(float dt)
{
	for (std::vector<GBaseProjectile*>::iterator it = mProjectileGroup.begin(); it != mProjectileGroup.end();)
	{
		if (!(*it)->IsAlive())
		{
			delete (*it);
			it = mProjectileGroup.erase(it);
		}
		else
		{
			(*it)->Update(dt);
			it++;
		}
	}
}

void GProjectileManager::Draw(float dt)
{
	for (std::vector<GBaseProjectile*>::iterator it = mProjectileGroup.begin(); it != mProjectileGroup.end(); it++) { (*it)->Draw(dt); }
}
