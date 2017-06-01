#pragma once

#include <FrameworkUPC\Sprite.h>

class GLogicCamera;
class GEngine;

class GBaseActor
{
public:
	GBaseActor() {}
	GBaseActor(GEngine* engine);
	~GBaseActor();

	float inline GetX() { return mX; }
	float inline GetY() { return mY; }
	void inline SetX(float x) { mX = x; }
	void inline SetY(float y) { mY = y; }

	float inline GetRotation() { return mSprite.GetRotationZ(); }
	void inline SetRotation(float value) { mSprite.SetRotationZ(value); }

	void Initialize(float x, float y, std::string path);
	void Update(float dt);
	void Draw(float dt);

	void Translate(float dx, float dy)
	{
		mX += dx;
		mY += dy;
	}

	void KillObject() { objectAlive = false; }
	bool IsAlive() { return objectAlive; }

protected:
	bool objectAlive;
	float mX;
	float mY;

	GEngine* mEngine;
	Sprite mSprite;
	GLogicCamera* mLogicCamera;
};

