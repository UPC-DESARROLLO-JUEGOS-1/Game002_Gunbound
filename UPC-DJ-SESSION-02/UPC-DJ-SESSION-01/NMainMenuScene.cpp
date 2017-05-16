#include "NMainMenuScene.h"
#include "NAppSceneGraph.h"
#include <UPCFramework\NFramework.h>

NMainMenuScene::NMainMenuScene(NAppSceneGraph* sceneGraph)
{
	NBaseScene::NBaseScene(sceneGraph);
}

void NMainMenuScene::Initialize() {
	NBaseCamera* camera = NFramework::GET_FRAMEWORK()->GetCamera();

	mTimeInterval = new NTimeInterval();
	mTimeInterval->Initialize(2.0f);
	mTimeInterval->OnEndInterval = std::bind(&NMainMenuScene::OnFinishInteval, this);	
}

void NMainMenuScene::OnFinishInteval() {
	NFramework::GET_FRAMEWORK()->GetSceneGraph()->GotoScene(EnumAppScenes::Game);
}

void NMainMenuScene::Update(float dt) {
	if (mTimeInterval != nullptr) {
		mTimeInterval->Update(dt);
	}
}

void NMainMenuScene::Draw(float dt) {
	
}

NMainMenuScene::~NMainMenuScene()
{
	delete mTimeInterval;

	NBaseScene::~NBaseScene();
}