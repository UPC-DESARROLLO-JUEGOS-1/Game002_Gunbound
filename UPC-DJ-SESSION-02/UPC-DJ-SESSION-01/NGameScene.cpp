#include "NGameScene.h"
#include "NAppSceneGraph.h"
#include <UPCFramework\NFramework.h>

#include <SDL\SDL_keycode.h>

NGameScene::NGameScene(NAppSceneGraph* sceneGraph) : 
	mIsDown(false), mIsUp(false), mIsLeft(false), mIsRight(false)
{
	NBaseScene::NBaseScene(sceneGraph);
}

void NGameScene::Initialize() {
	NBaseCamera* camera = NFramework::GET_FRAMEWORK()->GetCamera();

	mSprite = new NSprite();
	mSprite->Initialize(0, 0, "Sprites/spMario.png");
	mSprite->SetRenderCamera(camera);

	mQuad = new NPrimitiveQuad();
	mQuad->Initialize(200, 50, 150, 50, 20, 189, 100, 255);
	mQuad->SetRenderCamera(camera);

	mCircle = new NPrimitiveCircumference();
	mCircle->Initialize(200, 150, 10, 12);
	mCircle->SetRenderCamera(camera);
}

void NGameScene::OnKeyDown(SDL_Keycode code) {
	switch (code)
	{
		case SDLK_UP:		mIsUp = true;		break;
		case SDLK_DOWN:		mIsDown = true;		break;
		case SDLK_RIGHT:	mIsRight = true;	break;
		case SDLK_LEFT:		mIsLeft = true;		break;
	}
}

void NGameScene::OnKeyUp(SDL_Keycode code) {
	switch (code)
	{
		case SDLK_UP:		mIsUp = false;		break;
		case SDLK_DOWN:		mIsDown = false;	break;
		case SDLK_RIGHT:	mIsRight = false;	break;
		case SDLK_LEFT:		mIsLeft = false;	break;
	}
}

void NGameScene::Update(float dt) {
	if (mIsUp) { mSprite->SetY(mSprite->GetY() - 1); }
	if (mIsDown) { mSprite->SetY(mSprite->GetY() + 1); }
	if (mIsLeft) { mSprite->SetX(mSprite->GetX() - 1); }
	if (mIsRight) { mSprite->SetX(mSprite->GetX() + 1); }

	mSprite->Update(dt);
	mQuad->Update(dt);
	mCircle->Update(dt);
}

void NGameScene::Draw(float dt) {
	mSprite->Draw(dt);
	mQuad->Draw(dt);
	mCircle->Draw(dt);
}

NGameScene::~NGameScene()
{
	NBaseScene::~NBaseScene();
}