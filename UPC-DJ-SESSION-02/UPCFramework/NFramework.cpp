#include "NFramework.h"
#include "NEnumWindowFlags.h"
#include "NCamera2D.h"

#include <SDL\SDL.h>
#include <iostream>

NFramework* NFramework::M_FRAMEWORK;
NFramework* NFramework::GET_FRAMEWORK() { return M_FRAMEWORK; }

NFramework::NFramework() :
	mScreenWidth(0),
	mScreenHeight(0),
	mFrameworkState(NEnumFrameworkState::Running),
	mContentManagement(this),
	mShaderManagment(this)
{
	NFramework::M_FRAMEWORK = this;
}

void NFramework::Initialize(std::string windowName, const int screenWidth, const int screenHeight, 
	unsigned int windowFlags) {

	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;
	
	mWindow.Create(windowName, mScreenWidth, mScreenHeight, windowFlags);
	mWindow.AddInputListener(std::bind(&NFramework::OnListenInputsFromWindow, 
		this, std::placeholders::_1));

	mCamera = new NCamera2D();
	mCamera->Initialize(screenWidth, screenHeight);

	mContentManagement.Initialize();
	mShaderManagment.Initialize();

	mSceneGraph = new NSceneGraph();
	mSceneGraph->Initialize();

	//mContentManagement.LoadAndGetContent<NImageContent>("Sprites/spMario.png");
}

void NFramework::SetFrameworkState(NEnumFrameworkState state)
{
	mFrameworkState = state;
}

float NFramework::ComputeDeltaTime() {
	float deltaTime = 0.0f;

	static float previousTick = SDL_GetTicks();
	float currentTick = SDL_GetTicks();

	deltaTime = currentTick - previousTick;
	previousTick = currentTick;

	return deltaTime / 1000.0f;
}

void NFramework::OnListenInputsFromWindow(SDL_Event evnt) {
	// Invoke callback Input
	if (mOnInput != nullptr) {
		mOnInput(evnt);
	}

	switch (evnt.type) {
	case SDL_QUIT:
		mFrameworkState = NEnumFrameworkState::Exit;
		break;
	case SDL_KEYDOWN:
		mSceneGraph->OnKeyDown(evnt.key.keysym.sym);
		break;
	case SDL_KEYUP:
		mSceneGraph->OnKeyUp(evnt.key.keysym.sym);
		break;
		/*case SDL_MOUSEMOTION:
			
			break;
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym) {
			case SDLK_w:
				std::cout << "INPUT: W";
				break;
			}
			break;*/
	}
}

void NFramework::DoGameLoop(std::function<void(float)> onUpdate, std::function<void(float)> onDraw) {
	mOnUpdate = onUpdate;
	mOnDraw = onDraw;
	
	while (mFrameworkState != NEnumFrameworkState::Exit)
	{
		float deltaTime = ComputeDeltaTime();

		mWindow.Update(deltaTime);

		Update(deltaTime);
		Draw(deltaTime);
	}
}


void NFramework::Update(float dt) {
	mCamera->Update(dt);

	mSceneGraph->Update(dt);
	mOnUpdate(dt);
}

void NFramework::Draw(float dt) {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mSceneGraph->Draw(dt);
	mOnDraw(dt);

	mWindow.Present();
}

NFramework::~NFramework()
{
}