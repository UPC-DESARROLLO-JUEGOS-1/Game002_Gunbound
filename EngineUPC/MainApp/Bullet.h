#pragma once
#include <FrameworkUPC\Sprite.h>
#include <GameObject.h>

class Bullet : public GameObject
{
public:
	Bullet(BaseScene* scene) :
		GameObject::GameObject(scene),
		moveSpeed(400)
	{}
	~Bullet() {}

	void Initialize(float x, float y);
	void Update(float dt);
	void Draw(float dt);

private:
	float moveSpeed;
};