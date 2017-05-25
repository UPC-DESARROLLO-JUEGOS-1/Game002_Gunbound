#include "GameScene.h"
#include <FrameworkUPC\GameFramework.h>
#include "GameApp.h"

#include <iostream>

void GameScene::Initialize()
{
	GameFramework* framework = GameFramework::GET_FRAMEWORK();
	BaseCamera* camera = framework->GetCamera();

	mGGApp = new GunboundGameApp();
	mGGApp->Initialize();

	mPlayer = new GPlayer();
	mPlayer->Initialize(GameApp::WIDTH*0.5f, GameApp::HEIGHT, "Sprites/player.png");
}

void GameScene::OnKeyDown(SDL_Keycode key)
{
	mGGApp->OnKeyDown(key);
}

void GameScene::OnKeyUp(SDL_Keycode key)
{
	mGGApp->OnKeyUp(key);
}

void GameScene::Update(float dt)
{
	mGGApp->Update(dt);
	mPlayer->Update(dt);
}

void GameScene::Draw(float dt)
{
	mGGApp->Draw(dt);
	mPlayer->Draw(dt);
}
