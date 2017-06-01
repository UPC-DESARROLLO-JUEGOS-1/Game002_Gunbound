#include "GTurnManager.h"
#include "GEngine.h"
#include <iostream>

void GTurnManager::Initialize()
{
	mActivePlayerIndex = 1;
	mActivePlayer = mEngine->GetPlayer();
}

void GTurnManager::Update(float dt)
{
}

void GTurnManager::OnKeyDown(SDL_Keycode key)
{
	mActivePlayer->GetControl()->OnKeyDown(key);
}

void GTurnManager::OnKeyUp(SDL_Keycode key)
{
	mActivePlayer->GetControl()->OnKeyUp(key);

	switch (key)
	{
		case SDLK_u:
			ChangeActivePlayer();
			break;
	}
}

void GTurnManager::ChangeActivePlayer()
{
	std::cout << "Player Changed" << std::endl;
	mActivePlayer->GetControl()->SetInactive();

	switch (mActivePlayerIndex)
	{
		case 1:
			mActivePlayerIndex = 2;
			mActivePlayer = mEngine->GetPlayer2();
			break;
		case 2:
			mActivePlayerIndex = 1;
			mActivePlayer = mEngine->GetPlayer();
			break;
	}

	mEngine->GetLogicCamera()->SetCurrentTarget(mActivePlayer);
}
