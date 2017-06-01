#include "GEngine.h"
#include "GameApp.h"

#include <string>

void GEngine::Initialize() {
	mLogicCamera = new GLogicCamera(this);
	mPlayer = new GPlayer(this);
	mPlayer2 = new GPlayer(this);
	mWorld = new GWorld(this);
	mProjectileManager = new GProjectileManager(this);
	mTurnManager = new GTurnManager(this);
	
	mPlayer->Initialize(GameApp::WIDTH*0.5f, GameApp::HEIGHT*0.4, "Sprites/player.png");
	mPlayer2->Initialize(GameApp::WIDTH*0.5f+ GameApp::WIDTH*0.2f, GameApp::HEIGHT*0.4, "Sprites/player.png");

	mWorld->Initialize(0, 0, "Sprites/world.png");
	mProjectileManager->Initialize();
	mTurnManager->Initialize();
	mLogicCamera->Initialize();

	// After All
	mLogicCamera->SetCurrentTarget(mPlayer);
}

void GEngine::Update(float dt) {
	mLogicCamera->Update(dt);
	mWorld->Update(dt);
	mPlayer->Update(dt);
	mPlayer2->Update(dt);
	mProjectileManager->Update(dt);
	mTurnManager->Update(dt);
}

void GEngine::Draw(float dt) {
	mWorld->Draw(dt);
	mPlayer->Draw(dt);
	mPlayer2->Draw(dt);
	mProjectileManager->Draw(dt);
}

void GEngine::OnKeyDown(SDL_Keycode key)
{
	mTurnManager->OnKeyDown(key);
}

void GEngine::OnKeyUp(SDL_Keycode key)
{
	mTurnManager->OnKeyUp(key);
}