#include "GBaseProjectile.h"
#include "GWorldForces.h"

#include <FrameworkUPC\GameFramework.h>
#include <math.h>

void GBaseProjectile::Initialize(float x, float y, float angle, float strength)
{
	GBaseActor::Initialize(x, y, "Sprites/bullet.png");

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

	mX = mPosition0.x + (mSpeed0.x + mWind.x*mTimeParameter)*mTimeParameter*0.5f;
	mY = mPosition0.y + (mSpeed0.y + (mWind.y + mGravity.y)*mTimeParameter)*mTimeParameter*0.5f;
	
	GBaseActor::Update(dt);
}

void GBaseProjectile::Draw(float dt)
{
	if (!objectAlive) return;

	GBaseActor::Draw(dt);
}
