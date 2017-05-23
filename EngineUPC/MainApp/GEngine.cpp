#include "GEngine.h"
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
	mPlayer->Initialize(100, 200, "");

	mWorld = new GWorld();
	mWorld->Initialize("");

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