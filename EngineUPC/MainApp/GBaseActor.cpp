#include "GBaseActor.h"
#include "GunboundGameApp.h"
#include "GEngine.h"

#include <FrameworkUPC\GameFramework.h>

GBaseActor::GBaseActor(GEngine* engine) :
	mEngine(engine),
	objectAlive(true)
{
}

GBaseActor::~GBaseActor()
{
}

void GBaseActor::Initialize(float x, float y, std::string path) {
	mX = x;
	mY = y;
	mSprite.Initialize(mX, mY, path);
	mSprite.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());

	mLogicCamera = GunboundGameApp::GET_GAMEAPP()->
		GetEngine()->GetLogicCamera();
}

void GBaseActor::Update(float dt) {
	float sx = mX - mLogicCamera->GetX();
	float sy = mY - mLogicCamera->GetY();

	mSprite.SetX(sx);
	mSprite.SetY(sy);
	mSprite.Update(dt);
}

void GBaseActor::Draw(float dt) {
	mSprite.Draw(dt);
}