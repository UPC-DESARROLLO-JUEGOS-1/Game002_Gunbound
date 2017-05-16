#pragma once

#include <SDL\SDL.h>

class NBaseScene;

class NSceneGraph
{
public:
	NSceneGraph() : 
		mCurrentScene(nullptr) {}
	~NSceneGraph();

	void Initialize();
	virtual void GotoScene(int sceneId);

	void OnKeyDown(SDL_Keycode code);
	void OnKeyUp(SDL_Keycode code);
	void Update(float dt);
	void Draw(float dt);

protected:
	NBaseScene* mCurrentScene;

};

