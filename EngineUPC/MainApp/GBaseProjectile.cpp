#include "GBaseProjectile.h"
#include "GWorldForces.h"
#include "GEngine.h"
#include "GWorld.h"
#include "GLogicCamera.h"

#include <FrameworkUPC\GameFramework.h>
#include <math.h>

GBaseProjectile::GBaseProjectile(GEngine* engine) : GBaseActor::GBaseActor(engine),
	mTimeParameter(0.0f),
	mPower(30), // By default 30 radius explosion
	mPosition0(0, 0),
	mSpeed0(0, 0),
	mGravity(0, 0),
	mWind(0, 0) {

	mEngine = engine;
}

void GBaseProjectile::Initialize(float x, float y, float angle, float strength)
{
	GBaseActor::Initialize(x, y, "Sprites/bullet.png");

	mWorld = mEngine->GetWorld();
	mLogicCamera = mEngine->GetLogicCamera();

	//Position
	Vector2 pos = mSprite.GetPosition();
	mPosition0 = Vector2(pos.x - mSprite.GetWidth()*0.5f, pos.y - mSprite.GetHeight()*0.5f);
	mSprite.SetX(mPosition0.x);
	mSprite.SetY(mPosition0.y);

	//Speed
	mSpeed0 = Vector2(cosf(angle)*strength, sinf(angle)*strength);

	//World Forces
	GWorldForces* worldForces = GWorldForces::GET_WORLD_FORCES();
	mWind = worldForces->GetWind();
	mGravity = worldForces->GetGravity();
}

void GBaseProjectile::Update(float dt)
{
	if (!objectAlive) return;

	mTimeParameter += dt;

	float oldX = mX;
	float oldY = mY;

	mX = mPosition0.x + (mSpeed0.x + mWind.x*mTimeParameter)*mTimeParameter*0.5f;
	mY = mPosition0.y + (mSpeed0.y + (mWind.y + mGravity.y)*mTimeParameter)*mTimeParameter*0.5f;
	
	float dx = mX - oldX;
	float dy = mY - oldY;
	float angle = atan2f(dy, dx) + 1.57f;

	SetRotation(angle);

	Vector2 textureCoordinates = mWorld->ConvertToWorldTextureCoordinates(mX, mY);
	//textureCoordinates.x -= mLogicCamera->GetX();
	//textureCoordinates.y -= mLogicCamera->GetY();

	if (mWorld->ExistsTerrainIn(textureCoordinates.x, textureCoordinates.y))
	{
		mWorld->ExplodeTerrainIn(textureCoordinates.x, textureCoordinates.y, mPower);
		this->KillObject();
	}

	GBaseActor::Update(dt);
}

void GBaseProjectile::Draw(float dt)
{
	if (!objectAlive) return;

	GBaseActor::Draw(dt);
}


GBaseProjectile::~GBaseProjectile() {
	GBaseActor::~GBaseActor();
}