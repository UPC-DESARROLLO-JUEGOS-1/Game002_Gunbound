#pragma once

class GBaseActor;

class GLogicCamera
{
public:
	GLogicCamera();
	~GLogicCamera();

	float inline GetX() { return mX; }
	float inline GetY() { return mY; }
	GBaseActor* GetCurrentTarget() { return mCurrentTarget; }

	void Initialize();
	void Update(float dt);

	void SetCurrentTarget(GBaseActor* actor) {
		mCurrentTarget = actor;
	}

private:
	float mX;
	float mY;
	GBaseActor* mCurrentTarget;
};