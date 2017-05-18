#include "GameUI.h"

#include <FrameworkUPC\GameFramework.h>
#include "GameApp.h"

void GameUI::Initialize(int lives, int ammo)
{
	maxLives = lives;
	maxAmmo = ammo;

	BaseCamera* camera = GameFramework::GET_FRAMEWORK()->GetCamera();

	playerLives = std::vector<Sprite*>();
	for (int i = 0; i < maxLives; i++)
	{
		Sprite* lifeCounter = new Sprite();
		lifeCounter->Initialize(GameApp::WIDTH*0.01f + i * 70, 20, "Sprites/life.png");
		lifeCounter->SetRenderCamera(camera);
		playerLives.push_back(lifeCounter);
	}

	playerAmmo = std::vector<Sprite*>();
	for (int i = 0; i < maxAmmo; i++)
	{
		Sprite* ammoCounter = new Sprite();
		ammoCounter->Initialize(GameApp::WIDTH*0.95f - i * 40, 20, "Sprites/ammo.png");
		ammoCounter->SetRenderCamera(camera);
		playerAmmo.push_back(ammoCounter);
	}
}

void GameUI::Update(float dt)
{
	for (int i = 0; i < maxLives; i++) playerLives[i]->Update(dt);
	for (int i = 0; i < maxAmmo; i++) playerAmmo[i]->Update(dt);
}

void GameUI::Draw(float dt, int lives, int ammo)
{
	for (int i = 0; i < lives; i++) playerLives[i]->Draw(dt);
	for (int i = 0; i < ammo; i++) playerAmmo[i]->Draw(dt);
}
