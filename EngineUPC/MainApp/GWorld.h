#pragma once

#include <FrameworkUPC\Sprite.h>
#include "GWorldForces.h"

class GLogicCamera;
class GEngine;

class GWorld
{
public:
	GWorld(GEngine* engine);
	~GWorld()
	{
		delete mWorldForces;
	}

	int inline GetWidth() { return mWorldWidth; }
	int inline GetHeight() { return mWorldHeight; }

	void Initialize(float x, float y, std::string path);
	bool ExistsTerrainIn(int x, int y);
	void ExplodeTerrainIn(int x, int y, int radio);
	float GetFloorHeightIn(int x, int y);

	void Update(float dt);
	void Draw(float dt);

	Vector2 ConvertToWorldTextureCoordinates(int x, int y);

private:
	int mX;
	int mY;
	int mOffsetY;
	int mWorldWidth;
	int mWorldHeight;
	Sprite mSprite;
	GEngine* mEngine;
	GLogicCamera* mLogicCamera;
	GWorldForces* mWorldForces;

	bool InsideArea(int x, int y);
};

