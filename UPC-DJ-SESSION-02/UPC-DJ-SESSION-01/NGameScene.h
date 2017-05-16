#pragma once

#include <UPCFramework\NSprite.h>
#include <UPCFramework\NPrimitiveQuad.h>
#include <UPCFramework\NPrimitiveCircumference.h>
#include <UPCFramework\NBaseScene.h>

class NAppSceneGraph;

class NGameScene : public NBaseScene
{
public:
	NGameScene(NAppSceneGraph* sceneGraph);
	~NGameScene();

	void Initialize();
	void OnKeyDown(SDL_Keycode code);
	void OnKeyUp(SDL_Keycode code);
	void Update(float dt);
	void Draw(float dt);

private:
	bool mIsUp, mIsDown, mIsRight, mIsLeft;

	NSprite* mSprite;
	NPrimitiveQuad* mQuad;
	NPrimitiveCircumference* mCircle;
};

