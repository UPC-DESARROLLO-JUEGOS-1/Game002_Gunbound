#pragma once

#include <FrameworkUPC\SceneGraph.h>

#include "EnumAppScenes.h"
#include "GameScene.h"

class AppSceneGraph : public SceneGraph
{
public:
	AppSceneGraph() { SceneGraph::SceneGraph(); }
	~AppSceneGraph() { SceneGraph::~SceneGraph(); }

	void GoToScene(int sceneId)
	{
		BaseScene* result = nullptr;

		switch (sceneId)
		{
			case EnumAppScenes::MainMenu:
				break;
			case EnumAppScenes::Game:
				result = new GameScene(this);
				break;
			case EnumAppScenes::GameOver:
				break;
		}

		if (result != nullptr)
		{
			SceneGraph::GoToScene(sceneId);
			result->Initialize();
		}

		currentScene = result;
	}
};

