#include "Player.h"

#include <FrameworkUPC\GameFramework.h>
#include <GameApp.h>
#include "GameScene.h"

void Player::Initialize()
{
	GameFramework* framework = GameFramework::GET_FRAMEWORK();
	BaseCamera* camera = framework->GetCamera();

	body = new Sprite();
	body->Initialize(GameApp::WIDTH*0.5f, 0, "Sprites/player.png");
	body->SetRenderCamera(camera);
	body->SetY(GameApp::HEIGHT - body->GetHeight() - 30);

	reloadBar = new Quad();
	reloadBar->Initialize(0, 0, GameApp::WIDTH, 20);
	reloadBar->SetColor(255, 0, 0, 255);
	reloadBar->SetRenderCamera(camera);
	reloadBar->SetY(GameApp::HEIGHT - reloadBar->GetHeight());

	invulnerabilityWindow = new TimeInterval();
	invulnerabilityWindow->Initialize(invulnerabilityTime, 1, false);
	invulnerabilityWindow->onEndLoop = std::bind(&Player::LoseInvulnerability, this);
}

void Player::Update(float dt)
{
	if (!objectAlive) return;

	invulnerabilityWindow->Update(dt);

	if (reloading)
	{
		reloadBar->SetScaleX(reloadBar->GetScale().x - dt / reloadSpeed);
		if (reloadBar->GetScale().x <= 0)
		{
			reloading = false;
			bulletsRemaining = 3;
			reloadBar->SetScaleX(1.0f);
		}
	}

	SetSpeed(0, 0);
	if (isLeft && !isRight) SetSpeed(-moveSpeed, 0);
	if (isRight && !isLeft) SetSpeed(moveSpeed, 0);

	Move(dt);
	if (body->GetPosition().x < 0-body->GetWidth()) body->SetX(GameApp::WIDTH);
	if (body->GetPosition().x > GameApp::WIDTH) body->SetX(0 - body->GetWidth());

	body->Update(dt);
	reloadBar->Update(dt);
}

void Player::Draw(float dt)
{
	if (!objectAlive) return;

	body->Draw(dt);
	if(reloading) reloadBar->Draw(dt);
}

void Player::OnKeyDown(SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_LEFT:
			isLeft = true;
			break;
		case SDLK_RIGHT:
			isRight = true;
			break;
		case SDLK_SPACE:
			Shoot();
			break;
	}
}

void Player::OnKeyUp(SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_LEFT:
			isLeft = false;
			break;
		case SDLK_RIGHT:
			isRight = false;
			break;
	}
}

void Player::Shoot()
{
	Bullet* bulletAux = NULL;

	if (bulletsRemaining > 0 && objectAlive)
	{
		bulletAux = new Bullet(parentScene);
		Vector2 pos = body->GetPosition();
		bulletAux->Initialize(pos.x + body->GetWidth()*0.5f, pos.y + body->GetHeight()*0.5f);

		bulletsRemaining--;
		if (bulletsRemaining <= 0)
		{
			std::cout << "Reloading" << std::endl;
			reloading = true;
		}
	}

	if (bulletAux != NULL) ((GameScene*)parentScene)->OnPlayerShot(bulletAux);
}

void Player::GetHit()
{
	hitPoints--;
	moveSpeed = maxMoveSpeed*0.5f;
	invulnerable = true;
	body->SetColor(255, 255, 255, 128);
	invulnerabilityWindow->Reset();

	if (hitPoints == 0)
	{
		std::cout << "Game Lost" << std::endl;
		KillObject();
	}
}

void Player::LoseInvulnerability()
{
	moveSpeed = maxMoveSpeed;
	invulnerable = false;
	body->SetColor(255, 255, 255, 255);
}
