#pragma once

#include <UPCFramework\NBaseScene.h>
#include <UPCFramework\NTimeInterval.h>

class NAppSceneGraph;

class NMainMenuScene : public NBaseScene
{
public:
	NMainMenuScene(NAppSceneGraph* sceneGraph);
	~NMainMenuScene();

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnFinishInteval();

private:
	NTimeInterval* mTimeInterval;
};

