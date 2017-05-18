#include "GameApp.h"
#include <FrameworkUPC\EnumWindowFlags.h>
#include <iostream>

#include "AppSceneGraph.h"

GameApp::GameApp() {}
GameApp::~GameApp() {}

void GameApp::Start()
{
	InitializeApp();
	frameWork.MainLoop(std::bind(&GameApp::Update, this, std::placeholders::_1),
		std::bind(&GameApp::Draw, this, std::placeholders::_1));
}

void GameApp::InitializeApp()
{
	frameWork.Initialize("Game::Gunbound", GameApp::WIDTH, GameApp::HEIGHT, EnumWindowFlags::Windowed);
	frameWork.OnInput(std::bind(&GameApp::OnInput, this, std::placeholders::_1));

	frameWork.SetCustomSceneGraph(new AppSceneGraph());
	frameWork.GetSceneGraph()->GoToScene(EnumAppScenes::Game);
}

void GameApp::OnInput(SDL_Event evnt)
{
}

void GameApp::Update(float dt)
{
}

void GameApp::Draw(float dt)
{
}