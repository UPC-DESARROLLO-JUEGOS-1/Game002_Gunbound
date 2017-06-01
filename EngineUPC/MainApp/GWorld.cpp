#include "GWorld.h"
#include "GLogicCamera.h"
#include "GunboundGameApp.h"
#include <FrameworkUPC\GameFramework.h>

GWorld::GWorld(GEngine* engine) :
	mX(0), mY(0), mWorldWidth(0), mWorldHeight(0)
{
	mEngine = engine;
}

void GWorld::Initialize(float x, float y, std::string path) {
	mX = x;
	mY = y;

	mSprite.Initialize(0, 0, path);
	mSprite.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());

	mLogicCamera = GunboundGameApp::GET_GAMEAPP()->
		GetEngine()->GetLogicCamera();

	mWorldForces = new GWorldForces();

	mWorldWidth = mSprite.GetWidth();
	mWorldHeight = mSprite.GetHeight();
	mOffsetY = mLogicCamera->GetHeight() - mWorldHeight;

	ExplodeTerrainIn(200, 400, 120);
}

bool GWorld::ExistsTerrainIn(int x, int y) {
	bool inArea = InsideArea(x, y);
	bool result = false;

	if (inArea) {
		ImageContent* imageContent = mSprite.GetImageContent();
		NColor color = imageContent->GetPixel(x, y);

		result = ((int)color.a) > 0;
	}

	return result;
}
Vector2 GWorld::ConvertToWorldTextureCoordinates(int x, int y)
{
	int tX = x - mX;
	int tY = y - mY - mOffsetY;

	return Vector2(tX, tY);
}

void GWorld::ExplodeTerrainIn(int x, int y, int radius) {
	bool inArea = InsideArea(x, y);

	if (inArea) {
		ImageContent* imageContent = mSprite.GetImageContent();

		int dRadius = radius * radius;
		int sizeX = x + radius;
		int sizeY = y + radius;

		for (int i = x - radius; i < sizeX; i++) {
			for (int j = y - radius; j < sizeY; j++) {
				
				float dx = i - x;
				float dy = j - y;
				int d = dx * dx + dy* dy;

				if (d < dRadius) {
					imageContent->SetPixelAlpha(i, j, 0, false);
				}	
			}
		}

		imageContent->Invalidate();
	}
}

float GWorld::GetFloorHeightIn(int x, int y)
{
	bool inArea = InsideArea(x, y);
	float result = y;

	if (inArea)
	{
		ImageContent* imageContent = mSprite.GetImageContent();
		
		//Check Upwards
		int j = y-1;
		while (j >= 0)
		{
			NColor color = imageContent->GetPixel(x, j);
			if (color.a == 0)
			{
				result = j + 1;
				break;
			}
			j--;
		}

		//Check Downwards
		if (result == y)
		{
			j = y+1;
			while (j < imageContent->GetHeight())
			{
				NColor color = imageContent->GetPixel(x, j);
				if (color.a != 0)
				{
					result = j - 1;
					break;
				}
				j++;
			}
		}
	}

	return result + mY + mOffsetY;
}

bool GWorld::InsideArea(int x, int y) {
	return 
		(x >= 0 && x < mWorldWidth) && 
		(y >= 0 && y < mWorldHeight);
}

void GWorld::Update(float dt) {
	float sx = mX - mLogicCamera->GetX();
	float sy = mY - mLogicCamera->GetY();
	float limitLeftX = -(mWorldWidth - mLogicCamera->GetWidth());

	//sx = sx < limitLeftX ? limitLeftX : sx;
	//sx = sx < 0 ? 0 : sx;
	//sy = sy < 0 ? 0 : sy;

	sy += mOffsetY;

	mSprite.SetX(sx);
	mSprite.SetY(sy);
	mSprite.Update(dt);
}

void GWorld::Draw(float dt) {
	mSprite.Draw(dt);
}