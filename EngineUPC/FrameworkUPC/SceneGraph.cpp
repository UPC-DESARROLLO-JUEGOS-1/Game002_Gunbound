#include "SceneGraph.h"
#include "BaseScene.h"

SceneGraph::~SceneGraph()
{
	if (currentScene != nullptr)
	{
		currentScene->~BaseScene();
		currentScene = nullptr;
	}
}

void SceneGraph::Initialize()
{
}

void SceneGraph::Update(float dt)
{
	if (currentScene != nullptr) currentScene->Update(dt);
}

void SceneGraph::Draw(float dt)
{
	if (currentScene != nullptr) currentScene->Draw(dt);
}

void SceneGraph::OnKeyDown(SDL_Keycode key)
{
	if (currentScene != nullptr) currentScene->OnKeyDown(key);
}

void SceneGraph::OnKeyUp(SDL_Keycode key)
{
	if (currentScene != nullptr) currentScene->OnKeyUp(key);
}

void SceneGraph::GoToScene(int sceneId)
{
	if (currentScene != nullptr)
	{
		currentScene->~BaseScene();
		currentScene = nullptr;
	}
}
