#include "GBaseActor.h"
#include "GunboundGameApp.h"

GBaseActor::GBaseActor()
{
}

GBaseActor::~GBaseActor()
{
}

void GBaseActor::Initialize(float x, float y, std::string path) {
	mX = x;
	mY = y;
	mSprite.Initialize(mX, mY, path);

	mLogicCamera = GunboundGameApp::GET_GAMEAPP()->
		GetEngine()->GetLogicCamera();
}

void GBaseActor::Update(float dt) {
	float sx = mX - mLogicCamera->GetX();
	float sy = mY - mLogicCamera->GetY();

	mSprite.SetX(sx);
	mSprite.SetY(sy);
}

void GBaseActor::Draw(float dt) {

}