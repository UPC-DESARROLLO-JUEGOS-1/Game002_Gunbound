#include "Bullet.h"

#include <FrameworkUPC\GameFramework.h>
#include <GameApp.h>

void Bullet::Initialize(float x, float y)
{
	GameFramework* framework = GameFramework::GET_FRAMEWORK();
	BaseCamera* camera = framework->GetCamera();

	body = new Sprite();
	body->Initialize(x, y, "Sprites/bullet.png");
	body->SetRenderCamera(camera);

	Vector2 pos = body->GetPosition();
	body->SetX(pos.x - body->GetWidth()*0.5f);
	body->SetY(pos.y - body->GetHeight()*0.5f);

	SetSpeed(0, -moveSpeed);
}

void Bullet::Update(float dt)
{
	if (!objectAlive) return;

	Move(dt);
	if (body->GetPosition().y + body->GetHeight() <= 0)
	{
		KillObject();
		return;
	}
	body->Update(dt);
}

void Bullet::Draw(float dt)
{
	if (!objectAlive) return;

	body->Draw(dt);
}
