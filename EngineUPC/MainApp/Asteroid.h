#pragma once

#include <FrameworkUPC\Sprite.h>
#include "GameObject.h"

class Asteroid : public GameObject
{
public:
	Asteroid(BaseScene* scene) :
		GameObject::GameObject(scene),
		moveSpeed(200),
		rotationSpeed(5),
		hitPoints(1)
	{}

	~Asteroid(){}

	virtual void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void GetHit();
	
protected:
	float moveSpeed;
	float rotationSpeed;
	int hitPoints;
};

