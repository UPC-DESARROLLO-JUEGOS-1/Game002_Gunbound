#include "GProjectileManager.h"
#include "GameScene.h"
#include  <iostream>

void GProjectileManager::Initialize()
{
	mWorld = mEngine->GetWorld();
	mProjectileGroup = std::vector<GBaseProjectile*>();
}

void GProjectileManager::CreateProjectile(float x, float y, float angle, float strength) {
	GBaseProjectile* newProjectile = new GBaseProjectile(mEngine);
	newProjectile->Initialize(x, y, angle, strength);

	mProjectileGroup.push_back(newProjectile);

	// Now set it to the current camera
	mEngine->GetLogicCamera()->SetCurrentTarget(newProjectile);
}

void GProjectileManager::Update(float dt)
{
	std::vector<GBaseProjectile*>::iterator i = mProjectileGroup.begin();
	while (i != mProjectileGroup.end())
	{
		GBaseProjectile* bullet = (*i);

		if (bullet->IsAlive()) {
			bullet->Update(dt);
			++i;
		}
		else {
			i = mProjectileGroup.erase(i);
			//std::cout << "erase bullet";
		}
	}
}

void GProjectileManager::Draw(float dt)
{
	std::vector<GBaseProjectile*>::iterator i = mProjectileGroup.begin();
	while (i != mProjectileGroup.end())
	{
		GBaseProjectile* bullet = (*i);
		bullet->Draw(dt);

		++i;
	}
}
