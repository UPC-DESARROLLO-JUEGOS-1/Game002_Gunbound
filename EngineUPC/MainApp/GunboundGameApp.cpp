#include "GunboundGameApp.h"

GunboundGameApp* GunboundGameApp::GAMEAPP;
GunboundGameApp* GunboundGameApp::GET_GAMEAPP() { return GunboundGameApp::GAMEAPP; }

GunboundGameApp::GunboundGameApp()
{
	GunboundGameApp::GAMEAPP = this;
}

void GunboundGameApp::Initialize()
{
	mHud = new GHud();
	mHud->Initialize();

	mEngine = new GEngine();
	mEngine->Initialize();
}

void GunboundGameApp::OnKeyDown(SDL_Keycode key)
{
	mEngine->OnKeyDown(key);
}
void GunboundGameApp::OnKeyUp(SDL_Keycode key)
{
	mEngine->OnKeyUp(key);
}

void GunboundGameApp::Update(float dt)
{
	mEngine->Update(dt);
	mHud->Update(dt);
}

void GunboundGameApp::Draw(float dt)
{
	mEngine->Draw(dt);
	mHud->Draw(dt);
}
