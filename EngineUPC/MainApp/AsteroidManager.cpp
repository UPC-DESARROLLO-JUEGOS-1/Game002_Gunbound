#include "AsteroidManager.h"
#include "GameScene.h"
#include <FrameworkUPC\RandomGenerator.h>
#include "AsteroidBig.h"

void AsteroidManager::Initialize()
{
	asteroidGroup = std::vector<Asteroid*>();
	asteroidSpawnTimer = new TimeInterval();
	asteroidSpawnTimer->Initialize(asteroidSpawnTime);
	asteroidSpawnTimer->onEndLoop = std::bind(&AsteroidManager::SpawnAsteroid, this);

	asteroidGroupSpawnTimer = new TimeInterval();
	asteroidGroupSpawnTimer->Initialize(asteroidGroupSpawnTime);
	asteroidGroupSpawnTimer->onEndLoop = std::bind(&AsteroidManager::SpawnAsteroidGroup, this);
}

void AsteroidManager::Update(float dt)
{
	asteroidSpawnTimer->Update(dt);
	asteroidGroupSpawnTimer->Update(dt);

	for (std::vector<Asteroid*>::iterator it = asteroidGroup.begin(); it != asteroidGroup.end();)
	{
		if (!(*it)->IsAlive())
		{
			delete (*it);
			it = asteroidGroup.erase(it);
		}
		else
		{
			(*it)->Update(dt);
			it++;
		}
	}
}

void AsteroidManager::Draw(float dt)
{
	for (std::vector<Asteroid*>::iterator it = asteroidGroup.begin(); it != asteroidGroup.end(); it++) { (*it)->Draw(dt); }
}

void AsteroidManager::SpawnAsteroid()
{
	Asteroid* aux;

	if (RandomGenerator::RandomInt(1, 10) > 7) //30% chance for a big asteroid to spawn
	{
		aux = new AsteroidBig(parentScene);
	}
	else
	{
		aux = new Asteroid(parentScene);
	}
	
	aux->Initialize();
	asteroidGroup.push_back(aux);
}

void AsteroidManager::SpawnAsteroidGroup()
{
	for (int i = 0; i < asteroidGroupSize; i++)
	{
		SpawnAsteroid();
	}

	parentScene->OnAsteroidGroupSpawn();
	asteroidGroupSize++;
}