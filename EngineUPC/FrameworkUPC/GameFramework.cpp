#include "GameFramework.h"
#include "Camera2D.h"
#include <SDL\SDL.h>
#include <iostream>
#include <time.h>

GameFramework* GameFramework::FRAMEWORK;
GameFramework * GameFramework::GET_FRAMEWORK() { return FRAMEWORK; }

GameFramework::GameFramework():
	screenWidth(0),
	screenHeight(0),
	frameworkState(FrameworkState::Running),
	shaderManager(this),
	contentManager(this)
{
	GameFramework::FRAMEWORK = this;
	srand(time(NULL));
}

GameFramework::~GameFramework(){}

void GameFramework::Initialize(std::string windowName, int screenWidth, int screenHeight, unsigned int windowFlags)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

	window.Create(windowName, screenWidth, screenHeight, windowFlags);
	window.AddInputListener(std::bind(&GameFramework::OnListenInputsFromWindow, this, std::placeholders::_1));

	shaderManager.Initialize();
	contentManager.Initialize();
	camera = new Camera2D();
	camera->Initialize(screenWidth, screenHeight);
	sceneGraph = new SceneGraph();
	sceneGraph->Initialize();
}

void GameFramework::MainLoop(std::function<void(float)> onUpdate, std::function<void(float)> onDraw)
{
	this->onUpdate = onUpdate;
	this->onDraw = onDraw;

	while (frameworkState != FrameworkState::Exit)
	{
		float deltaTime = ComputeDeltaTime();
		window.Update(deltaTime);
		Update(deltaTime);
		Draw(deltaTime);
	}
}

void GameFramework::Update(float dt)
{
	camera->Update(dt);
	sceneGraph->Update(dt);
	onUpdate(dt);
}

void GameFramework::Draw(float dt)
{
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sceneGraph->Draw(dt);
	onDraw(dt);
	window.Present();
}

float GameFramework::ComputeDeltaTime()
{
	float deltaTime = 0.0f;

	static float previousTick = SDL_GetTicks();
	float currentTick = SDL_GetTicks();

	deltaTime = currentTick - previousTick;
	previousTick = currentTick;

	return deltaTime*0.001f;
}

void GameFramework::OnListenInputsFromWindow(SDL_Event evnt)
{
	if (onInput != nullptr)
	{
		onInput(evnt);
	}

	switch (evnt.type)
	{
		case SDL_QUIT:
			frameworkState = FrameworkState::Exit;
			break;
		case SDL_KEYDOWN:
			sceneGraph->OnKeyDown(evnt.key.keysym.sym);
			break;
		case SDL_KEYUP:
			sceneGraph->OnKeyUp(evnt.key.keysym.sym);
			break;
		default:
			break;
	}
}
