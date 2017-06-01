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
	mSprite.SetPivot(0.5f);

	mCannon.Initialize(mX + mSprite.GetVisibleWidth()*0.7f, mY, "Sprites/cannon.png");
	mCannon.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());
	mCannon.SetY(mY - 6);
	mCannon.SetPivot(0.0f, 1.0f);

	mPlayerControl = new GPlayerControl(this, mEngine);
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
	float px = mX + mSprite.GetWidth()*0.5f;
	float py = mY + mSprite.GetHeight()*0.5f;

	mEngine->GetProjectileManager()->CreateProjectile(px, py, angle, strength);
}