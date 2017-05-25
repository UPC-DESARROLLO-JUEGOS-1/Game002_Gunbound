#pragma once

class GBaseActor;
class GEngine;
class GWorld;

class GLogicCamera
{
public:
	GLogicCamera(GEngine* engine);
	GLogicCamera() {}
	~GLogicCamera();

	float inline GetX() { return mX; }
	float inline GetY() { return mY; }
	float inline GetWidth() { return mWidth; }
	float inline GetHeight() { return mHeight; }
	GBaseActor* GetCurrentTarget() { return mCurrentTarget; }

	void Initialize();
	void Update(float dt);

	void SetCurrentTarget(GBaseActor* actor) {
		mCurrentTarget = actor;
	}

private:
	float mX;
	float mY;
	float mWidth;
	float mHeight;
	float mHWidth;
	float mHHeight;
	GBaseActor* mCurrentTarget;

	GEngine* mEngine;
	GWorld* mWorld;
};