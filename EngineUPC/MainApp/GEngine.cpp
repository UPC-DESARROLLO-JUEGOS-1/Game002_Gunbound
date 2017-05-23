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

	mPlayer = new GPlayer();
	mPlayer->Initialize(100, 200, "");

	// After All
	//mLogicCamera->SetCurrentTarget(mPlayer);
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
}

void GEngine::Draw(float dt) {
	mPlayer->Draw(dt);
}