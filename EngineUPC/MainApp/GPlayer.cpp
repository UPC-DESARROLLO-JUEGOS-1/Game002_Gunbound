#include "GPlayer.h"
#include "GEngine.h"

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

	mPlayerControl = new GPlayerControl(this);
	mPlayerControl->Initialize();
}

void GPlayer::Update(float dt) {
	mPlayerControl->Update(dt);
	mSprite.Update(dt);
}

void GPlayer::Draw(float dt) {
	mSprite.Draw(dt);
}
