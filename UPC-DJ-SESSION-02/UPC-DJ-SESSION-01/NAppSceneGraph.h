#pragma once

#include <UPCFramework\NSceneGraph.h>
#include "EnumAppScenes.h"

// escenas
#include "NGameScene.h"
#include "NMainMenuScene.h"

class NAppSceneGraph : public NSceneGraph
{
public:
	NAppSceneGraph() { NSceneGraph::NSceneGraph(); }
	~NAppSceneGraph() { NSceneGraph::~NSceneGraph(); }

	void GotoScene(int sceneId) {
		NBaseScene* result = nullptr;

		switch (sceneId) {
			case EnumAppScenes::MainMenu:
				result = new NMainMenuScene(this);
				break;
			case EnumAppScenes::Game:
				result = new NGameScene(this);
				break;
			case EnumAppScenes::Scorecard:
				break;
		}

		if (result != nullptr) {
			NSceneGraph::GotoScene(sceneId);

			result->Initialize();

			mCurrentScene = result;
		}
	}
};

