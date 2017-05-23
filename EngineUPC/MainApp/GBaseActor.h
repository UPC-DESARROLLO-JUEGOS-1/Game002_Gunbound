#pragma once

#include <FrameworkUPC\Sprite.h>

class GLogicCamera;

class GBaseActor
{
public:
	GBaseActor();
	~GBaseActor();

	float inline GetX() { return mX; }
	float inline GetY() { return mY; }

	void Initialize(float x, float y, std::string path);
	void Update(float dt);
	void Draw(float dt);

protected:
	float mX;
	float mY;

	Sprite mSprite;
	GLogicCamera* mLogicCamera;
};

