#include "GEngine.h"
#include "GameApp.h"

#include <string>

GEngine::GEngine()
{
}

GEngine::~GEngine()
{
}

void GEngine::Initialize() {
	mLogicCamera = new GLogicCamera();
	mLogicCamera->Initialize();

	mPlayer = new GPlayer(this);
	mPlayer->Initialize(GameApp::WIDTH*0.5f, GameApp::HEIGHT, "Sprites/player.png");

	mWorld = new GWorld();
	mWorld->Initialize(0, 0, "Sprites/world.png");

	// After All
	mLogicCamera->SetCurrentTarget(mPlayer);
}

void GEngine::OnKeyDown(SDL_Keycode key)
{
	mPlayer->GetControl()->OnKeyDown(key);
}

void GEngine::OnKeyUp(SDL_Keycode key)
{
	mPlayer->GetControl()->OnKeyUp(key);
}

void GEngine::Update(float dt) {
	mLogicCamera->Update(dt);
	mPlayer->Update(dt);
	mWorld->Update(dt);
}

void GEngine::Draw(float dt) {
	mWorld->Draw(dt);
	mPlayer->Draw(dt);
}