#pragma once

#include <SDL\SDL.h>

class BaseScene;

class SceneGraph
{
public:
	SceneGraph() :
		currentScene(nullptr)
	{}
	~SceneGraph();

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	virtual void GoToScene(int sceneId);
protected:
	BaseScene* currentScene;
};

