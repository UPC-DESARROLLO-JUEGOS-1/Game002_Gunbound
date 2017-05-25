#include "GPlayer.h"
#include "GEngine.h"
#include <FrameworkUPC\GameFramework.h>

GPlayer::GPlayer(GEngine* engine)
{
	mEngine = engine;

	GBaseActor::GBaseActor(engine);
}

GPlayer::~GPlayer()
{
	GBaseActor::~GBaseActor();
}

void GPlayer::Initialize(float x, float y, std::string path) {
	GBaseActor::Initialize(x, y, path);

	mY -= mSprite.GetHeight() - 30;

	mCannon.Initialize(mSprite.GetPosition().x + mSprite.GetVisibleWidth()*0.7f, mSprite.GetPosition().y, "Sprites/cannon.png");
	mCannon.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());
	mCannon.SetY(mSprite.GetPosition().y - 6);
	mCannon.SetPivot(0.0f, 1.0f);

	mPlayerControl = new GPlayerControl(this);
	mPlayerControl->Initialize(&mSprite, &mCannon);
}

void GPlayer::Update(float dt) {
	mPlayerControl->Update(dt);
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
	Vector2 pos = mSprite.GetPosition();
	newProjectile->Initialize(pos.x + mSprite.GetWidth()*0.5f, pos.y + mSprite.GetHeight()*0.5f, angle, strength);

	mEngine->OnPlayerShot(newProjectile);
}