#pragma once

#include <FrameworkUPC\Sprite.h>

class GWorld
{
public:
	GWorld();
	~GWorld();

	bool ExistsTerrainIn(float x, float y);
	void ExplodeTerrainIn(float x, float y, float radio);

	void Update(float dt);
	void Draw(float dt);

private:
	Sprite mSprite;
};

