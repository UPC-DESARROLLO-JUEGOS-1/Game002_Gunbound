#include "GPlayerControl.h"
//#include "GunboundGameApp.h"
#include "GPlayer.h"

GPlayerControl::GPlayerControl(GPlayer* player)
{
	mPlayer = player;
}

GPlayerControl::~GPlayerControl()
{
}

void GPlayerControl::Initialize() {
	//GunboundGameApp::GET_GAMEAPP()->GetEngine()->;
}

void GPlayerControl::OnKeyDown(SDL_Keycode key) {

}

void GPlayerControl::OnKeyUp(SDL_Keycode key) {

}

void GPlayerControl::Update(float dt) {



}
