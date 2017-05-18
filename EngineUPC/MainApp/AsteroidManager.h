#pragma once

#include <vector>
#include <FrameworkUPC\TimeInterval.h>
#include "Asteroid.h"

class GameScene;

class AsteroidManager
{
public:
	AsteroidManager(GameScene* parentScene) :
		asteroidSpawnTime(2.0f),
		asteroidGroupSpawnTime(8.0f),
		asteroidGroupSize(2)
	{
		this->parentScene = parentScene;
	}
	~AsteroidManager()
	{
		parentScene = nullptr;
		delete asteroidSpawnTimer;
		delete asteroidGroupSpawnTimer;
		for each (Asteroid* asteroid in asteroidGroup) { delete asteroid; }
	}

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	std::vector<Asteroid*>* GetAsteroids() { return &asteroidGroup; }

private:
	GameScene* parentScene;

	std::vector<Asteroid*> asteroidGroup;
	TimeInterval* asteroidSpawnTimer;
	float asteroidSpawnTime;
	TimeInterval* asteroidGroupSpawnTimer;
	float asteroidGroupSpawnTime;
	int asteroidGroupSize;

	void SpawnAsteroid();
	void SpawnAsteroidGroup();
};

