#include "GProjectileManager.h"
#include "GameScene.h"
#include  <iostream>
void GProjectileManager::Initialize()
{
	mWorld = mEngine->GetWorld();
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

			//Console::
			GLogicCamera* camera = mEngine->GetLogicCamera();
			Vector2 textureCoordinates = mWorld->ConvertToWorldTextureCoordinates((*it)->GetX(), (*it)->GetY());
			//textureCoordinates.x -= camera->GetX();
			textureCoordinates.y -= camera->GetY();

			//std::cout << "bullet x: " << textureCoordinates.x << " y: " << textureCoordinates.y << "\n";

			if (mWorld->ExistsTerrainIn(textureCoordinates.x, textureCoordinates.y))
			{
				mWorld->ExplodeTerrainIn(textureCoordinates.x, textureCoordinates.y, 30); // Remplazar número por variable de poder
				(*it)->KillObject();
			}
			it++;
		}
	}
}

void GProjectileManager::Draw(float dt)
{
	for (std::vector<GBaseProjectile*>::iterator it = mProjectileGroup.begin(); it != mProjectileGroup.end(); it++) { (*it)->Draw(dt); }
}
