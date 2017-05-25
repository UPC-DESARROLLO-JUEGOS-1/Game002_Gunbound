#pragma once

#include <FrameworkUPC\Sprite.h>
#include "GWorldForces.h"

class GLogicCamera;

class GWorld
{
public:
	GWorld();
	~GWorld()
	{
		delete mWorldForces;
	}

	int inline GetWidth() { return mWorldWidth; }
	int inline GetHeight() { return mWorldHeight; }

	void Initialize(float x, float y, std::string path);
	bool ExistsTerrainIn(int x, int y);
	void ExplodeTerrainIn(int x, int y, int radio);

	void Update(float dt);
	void Draw(float dt);

private:
	int mX;
	int mY;
	int mOffsetY;
	int mWorldWidth;
	int mWorldHeight;
	Sprite mSprite;
	GLogicCamera* mLogicCamera;
	GWorldForces* mWorldForces;

	bool InsideArea(int x, int y);
};

