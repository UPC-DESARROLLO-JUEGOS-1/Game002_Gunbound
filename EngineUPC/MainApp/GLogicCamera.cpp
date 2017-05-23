#include "GLogicCamera.h"
#include "GBaseActor.h"

GLogicCamera::GLogicCamera() :
	mX(0), mY(0)
{
}

GLogicCamera::~GLogicCamera()
{
}

void GLogicCamera::Initialize() {

}

void GLogicCamera::Update(float dt) {
	if (mCurrentTarget != nullptr) {
		mX = mCurrentTarget->GetX();
		mY = mCurrentTarget->GetY();
	}
}