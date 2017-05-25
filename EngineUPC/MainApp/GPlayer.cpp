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

	mSprite.SetY(mSprite.GetPosition().y - mSprite.GetHeight() - 30);

	mCannon.Initialize(mSprite.GetPosition().x + mSprite.GetVisibleWidth()*0.7f, mSprite.GetPosition().y, "Sprites/cannon.png");
	mCannon.SetRenderCamera(GameFramework::GET_FRAMEWORK()->GetCamera());
	mCannon.SetY(mSprite.GetPosition().y - 6);
	mCannon.SetPivot(0.0f, 1.0f);

	mPlayerControl = new GPlayerControl(this);
	mPlayerControl->Initialize();
}

void GPlayer::Update(float dt) {
	mPlayerControl->Update(dt);
	mSprite.Update(dt);
	mCannon.Update(dt);
}

void GPlayer::Draw(float dt) {
	mSprite.Draw(dt);
	mCannon.Draw(dt);
}
