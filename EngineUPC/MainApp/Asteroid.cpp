#include "Asteroid.h"

#include <FrameworkUPC\GameFramework.h>
#include <FrameworkUPC\RandomGenerator.h>
#include "GameApp.h"

void Asteroid::Initialize()
{
	GameFramework* framework = GameFramework::GET_FRAMEWORK();
	BaseCamera* camera = framework->GetCamera();

	body = new Sprite();
	body->Initialize(0, 0, "Sprites/asteroid.png");
	body->SetRenderCamera(camera);
	body->SetY(-body->GetHeight());
	body->SetX(RandomGenerator::RandomInt(0, GameApp::WIDTH - body->GetWidth()));

	SetSpeed(0, moveSpeed);
}

void Asteroid::Update(float dt)
{
	if (!objectAlive) return;

	Move(dt);
	body->SetRotationZ(body->GetRotationZ() + rotationSpeed * dt);

	if (body->GetPosition().y > GameApp::HEIGHT)
	{
		KillObject();
		return;
	}

	body->Update(dt);
}

void Asteroid::Draw(float dt)
{
	if (!objectAlive) return;

	body->Draw(dt);
}

void Asteroid::GetHit()
{
	hitPoints--;

	if (hitPoints == 0)
	{
		std::cout << "Asteroid Destroyed" << std::endl;
		KillObject();
	}
}
