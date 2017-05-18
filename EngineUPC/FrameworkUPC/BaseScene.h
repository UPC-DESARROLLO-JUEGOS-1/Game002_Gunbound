#pragma once

#include "SceneGraph.h"

class BaseScene
{
public:
	BaseScene(SceneGraph* sceneGraph)
	{
		this->sceneGraph = sceneGraph;
	}
	virtual ~BaseScene() {}

	virtual void Initialize() {}
	virtual void Update(float dt) {}
	virtual void Draw(float dt) {}

	virtual void OnKeyDown(SDL_Keycode key) {}
	virtual void OnKeyUp(SDL_Keycode key) {}
	
private:
	SceneGraph* sceneGraph;
};

