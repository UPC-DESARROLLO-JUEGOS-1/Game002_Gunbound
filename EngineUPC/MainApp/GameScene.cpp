#include "GameScene.h"
#include <FrameworkUPC\GameFramework.h>
#include "GameApp.h"

#include <iostream>

void GameScene::Initialize()
{
	GameFramework* framework = GameFramework::GET_FRAMEWORK();
	BaseCamera* camera = framework->GetCamera();
}

void GameScene::Update(float dt)
{
}

void GameScene::Draw(float dt)
{
}

void GameScene::OnKeyDown(SDL_Keycode key)
{
	
}

void GameScene::OnKeyUp(SDL_Keycode key)
{
	
}