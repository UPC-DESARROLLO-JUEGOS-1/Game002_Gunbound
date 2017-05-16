#pragma once

#include "NSceneGraph.h"

class NBaseScene
{
public:
	NBaseScene() {}
	NBaseScene(NSceneGraph* sceneGraph) { mSceneGraph = sceneGraph; }
	virtual ~NBaseScene() {
		mSceneGraph = nullptr;
	}

	virtual void Initialize() {}
	virtual void OnKeyDown(SDL_Keycode code) {}
	virtual void OnKeyUp(SDL_Keycode code) {}

	virtual void Update(float dt) {}
	virtual void Draw(float dt) {}

private:
	NSceneGraph* mSceneGraph;
};

