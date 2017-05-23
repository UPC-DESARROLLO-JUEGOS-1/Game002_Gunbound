#include "GPlayer.h"

GPlayer::GPlayer()
{
	GBaseActor::GBaseActor();
}

GPlayer::~GPlayer()
{
	GBaseActor::~GBaseActor();
}

void GPlayer::Initialize(float x, float y, std::string path) {
	GBaseActor::Initialize(x, y, path);

	mPlayerControl.Initialize();
}

void GPlayer::Update(float dt) {
	mPlayerControl.Update(dt);
}

void GPlayer::Draw(float dt) {

}
