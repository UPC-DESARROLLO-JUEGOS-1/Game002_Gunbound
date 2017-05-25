#include "GLogicCamera.h"
#include "GBaseActor.h"
#include "GameApp.h"

GLogicCamera::GLogicCamera() :
	mX(0), mY(0), 
	mWidth(GameApp::WIDTH), mHeight(GameApp::HEIGHT),
	mHWidth(GameApp::WIDTH * 0.5f), mHHeight(GameApp::HEIGHT * 0.5f)
{
}

GLogicCamera::~GLogicCamera()
{
}

void GLogicCamera::Initialize() {

}

void GLogicCamera::Update(float dt) {
	if (mCurrentTarget != nullptr) {
		float cx = mCurrentTarget->GetX();
		float cy = mCurrentTarget->GetY();
	
		if (cx > mHWidth) { mX = cx - mHWidth; }
		if (cy > mHHeight) { mY = cy - mHHeight; }
	}
}