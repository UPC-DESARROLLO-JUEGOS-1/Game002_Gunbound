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

	mPlayerControl = new GPlayerControl(this);
	mPlayerControl->Initialize();
}

void GPlayer::Update(float dt) {
	mPlayerControl->Update(dt);
}

void GPlayer::Draw(float dt) {

}
