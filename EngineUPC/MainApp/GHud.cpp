#include "GHud.h"
#include "GameApp.h"
#include <FrameworkUPC\GameFramework.h>

void GHud::Initialize()
{
	mPlayerChargeBar.Initialize(0, 0, GameApp::WIDTH, 20);
	mPlayerChargeBar.SetColor(255, 0, 0, 255);
	mPlayerChargeBar.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());
	mPlayerChargeBar.SetY(GameApp::HEIGHT - mPlayerChargeBar.GetHeight());
}

void GHud::Update(float dt)
{
	mPlayerChargeBar.Update(dt);
}

void GHud::Draw(float dt)
{
	mPlayerChargeBar.Draw(dt);
}