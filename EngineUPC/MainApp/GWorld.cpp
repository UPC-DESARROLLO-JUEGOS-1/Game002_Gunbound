#include "GWorld.h"
#include "GLogicCamera.h"
#include "GunboundGameApp.h"
#include <FrameworkUPC\GameFramework.h>

GWorld::GWorld() :
	mX(0), mY(0), mWorldWidth(0), mWorldHeight(0)
{
}

GWorld::~GWorld()
{
}

void GWorld::Initialize(std::string path) {
	mSprite.Initialize(0, 0, path);
	mSprite.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());

	mWorldWidth = mSprite.GetWidth();
	mWorldHeight = mSprite.GetHeight();

	mWorldForces = new GWorldForces();

	mLogicCamera = GunboundGameApp::GET_GAMEAPP()->
		GetEngine()->GetLogicCamera();
}

bool GWorld::ExistsTerrainIn(int x, int y) {
	bool inArea = InsideArea(x, y);

	if (inArea) {
		// TODO
	}

	return false;
}

void GWorld::ExplodeTerrainIn(int x, int y, int radio) {
	bool inArea = InsideArea(x, y);

	if (inArea) {
		// TODO
	}
}

bool GWorld::InsideArea(int x, int y) {
	return 
		(x >= 0 && x < mWorldWidth) && 
		(y >= 0 && y < mWorldHeight);
}

void GWorld::Update(float dt) {
	float sx = mX - mLogicCamera->GetX();
	float sy = mY - mLogicCamera->GetY();

	mSprite.SetX(sx);
	mSprite.SetY(sy);
	mSprite.Update(dt);
}

void GWorld::Draw(float dt) {
	mSprite.Draw(dt);
}