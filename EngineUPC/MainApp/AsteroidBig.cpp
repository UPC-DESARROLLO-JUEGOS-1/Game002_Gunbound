#include "AsteroidBig.h"

#include <FrameworkUPC\GameFramework.h>
#include <FrameworkUPC\RandomGenerator.h>
#include "GameApp.h"

void AsteroidBig::Initialize()
{
	GameFramework* framework = GameFramework::GET_FRAMEWORK();
	BaseCamera* camera = framework->GetCamera();

	body = new Sprite();
	body->Initialize(0, 0, "Sprites/asteroidBig.png");
	body->SetRenderCamera(camera);
	body->SetY(-body->GetHeight());
	body->SetX(RandomGenerator::RandomInt(0, GameApp::WIDTH - body->GetWidth()));

	moveSpeed *= 0.5f;
	rotationSpeed *= 0.5f;
	hitPoints = 2;

	SetSpeed(0, moveSpeed);
}
