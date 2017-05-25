#include "GPlayer.h"
#include "GEngine.h"
#include <FrameworkUPC\GameFramework.h>

GPlayer::GPlayer(GEngine* engine)
{
	mEngine = engine;

	GBaseActor::GBaseActor(engine);
}

void GPlayer::Initialize(float x, float y, std::string path) {
	GBaseActor::Initialize(x, y, path);

	mY -= mSprite.GetHeight() - 30;

	mCannon.Initialize(mX + mSprite.GetVisibleWidth()*0.7f, mY, "Sprites/cannon.png");
	mCannon.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());
	mCannon.SetY(mY - 6);
	mCannon.SetPivot(0.0f, 1.0f);

	mPlayerControl = new GPlayerControl(this);
	mPlayerControl->Initialize(&mSprite, &mCannon);
}

void GPlayer::Update(float dt) {
	mPlayerControl->Update(dt);

	float limitRight = mEngine->GetWorld()->GetWidth() - mSprite.GetVisibleWidth();

	if (mX < 0) { mX = 0; }
	if (mX > limitRight) { mX = limitRight; }

	mCannon.Update(dt);
	GBaseActor::Update(dt);
}

void GPlayer::Draw(float dt) {
	GBaseActor::Draw(dt);
	mCannon.Draw(dt);
}

void GPlayer::Shoot(float angle, float strength)
{
	GBaseProjectile* newProjectile = new GBaseProjectile(mEngine);
	newProjectile->Initialize(mX + mSprite.GetWidth()*0.5f, mY + mSprite.GetHeight()*0.5f, angle, strength);

	mEngine->OnPlayerShot(newProjectile);
}