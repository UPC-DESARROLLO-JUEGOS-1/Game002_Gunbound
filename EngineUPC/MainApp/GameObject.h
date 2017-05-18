#pragma once

#include <FrameworkUPC\BaseScene.h>
#include <FrameworkUPC\Sprite.h>
#include <FrameworkUPC\Vector2.h>
#include <FrameworkUPC\CollisionHelper.h>

class GameObject
{
public:
	GameObject(BaseScene* scene) :
		speed(0.0f, 0.0f),
		objectAlive(true)
	{
		parentScene = scene;
	}
	~GameObject()
	{
		parentScene = nullptr;
		delete body;
	}

	virtual void Initialize() {}
	virtual void Update(float dt) {}
	virtual void Draw(float dt) {}

	Sprite* GetBody() { return body; }
	void KillObject() { objectAlive = false; }
	bool IsAlive() { return objectAlive; }
	static bool CheckCollision(GameObject* a, GameObject* b) { return CollisionHelper::HitTest(a->body, b->body); }

protected:
	BaseScene* parentScene;
	Sprite* body;
	Vector2 speed;
	bool objectAlive;

	void SetSpeed(float dx, float dy)
	{
		speed.x = dx;
		speed.y = dy;
	}
	void Move(float dt)
	{
		if (speed.x == 0.0f && speed.y == 0.0f) return;
		body->Translate(speed.x*dt, speed.y*dt);
	}
};

