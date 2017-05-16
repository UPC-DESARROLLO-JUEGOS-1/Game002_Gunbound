#include "NSceneGraph.h"
#include "NBaseScene.h"

void NSceneGraph::Initialize() {
	
}

void NSceneGraph::GotoScene(int sceneId) {
	if (mCurrentScene != nullptr) {
		mCurrentScene->~NBaseScene();
		mCurrentScene = nullptr;
	}
}

void NSceneGraph::OnKeyDown(SDL_Keycode code) {
	if (mCurrentScene != nullptr) {
		mCurrentScene->OnKeyDown(code);
	}
}

void NSceneGraph::OnKeyUp(SDL_Keycode code) {
	if (mCurrentScene != nullptr) {
		mCurrentScene->OnKeyUp(code);
	}
}

void NSceneGraph::Update(float dt) {
	if (mCurrentScene != nullptr) {
		mCurrentScene->Update(dt);
	}
}

void NSceneGraph::Draw(float dt) {
	if (mCurrentScene != nullptr) {
		mCurrentScene->Draw(dt);
	}
}

NSceneGraph::~NSceneGraph() {
	if (mCurrentScene != nullptr) {
		mCurrentScene->~NBaseScene();
		mCurrentScene = nullptr;
	}
}