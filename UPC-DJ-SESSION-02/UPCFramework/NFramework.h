#pragma once

#include <functional>
#include "NWindow.h"
#include "NContentManagement.h"
#include "NShaderManagment.h"
#include "NSceneGraph.h"

#include "NBaseCamera.h"

enum NEnumFrameworkState {
	Running,
	Exit
};

class NFramework
{
public:
	static NFramework* GET_FRAMEWORK();

	NFramework();
	~NFramework();

	NContentManagement* GetContentManagement() { return &mContentManagement; }
	NShaderManagment* GetShaderManagment() { return &mShaderManagment; }
	NBaseCamera* GetCamera() { return mCamera; }
	NSceneGraph* GetSceneGraph() { return mSceneGraph; }

	void Initialize(std::string windowName, int screenWidth, int screenHeight, 
		unsigned int windowFlags);

	void SetFrameworkState(NEnumFrameworkState state);
	void OnInput(std::function<void(SDL_Event)> onInput) { mOnInput = onInput; }
	void SetCustomSceneGraph(NSceneGraph* sceneGraph) { 
		mSceneGraph = sceneGraph;
		mSceneGraph->Initialize();
	}

	void DoGameLoop(std::function<void(float)> onUpdate, std::function<void(float)> onDraw);
	void Update(float dt);
	void Draw(float dt);

private:
	static NFramework* M_FRAMEWORK;

	int mScreenWidth;
	int mScreenHeight;
	NEnumFrameworkState mFrameworkState;
	NWindow mWindow;
	NShaderManagment mShaderManagment;
	NContentManagement mContentManagement;
	NSceneGraph* mSceneGraph;

	NBaseCamera* mCamera;

	std::function<void(SDL_Event)> mOnInput = NULL;
	std::function<void(float)> mOnUpdate = NULL;
	std::function<void(float)> mOnDraw = NULL;

	float ComputeDeltaTime();
	void OnListenInputsFromWindow(SDL_Event evnt);
};

