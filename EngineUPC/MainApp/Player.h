#pragma once

#include <vector>
#include <FrameworkUPC\BaseScene.h>
#include <FrameworkUPC\Quad.h>
#include <FrameworkUPC\Sprite.h>
#include <FrameworkUPC\TimeInterval.h>
#include "Bullet.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(BaseScene* scene) :
		GameObject::GameObject(scene),
		isLeft(false), isRight(false),
		maxMoveSpeed(600),
		moveSpeed(maxMoveSpeed),
		hitPoints(3),
		invulnerabilityTime(1.5f),
		invulnerable(false),
		bulletsRemaining(3),
		reloading(false),
		reloadSpeed(3.0f)
	{}
	~Player()
	{
		delete reloadBar;
		delete invulnerabilityWindow;
	}

	void Initialize();
	void Update(float dt);
	void Draw(float dt);
	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	void Shoot();
	void IncreaseSpeed(float value) { maxMoveSpeed += value; }
	void GetHit();
	bool IsInvulnerable() { return invulnerable; }
	int GetHP() { return hitPoints; }
	int GetAmmo() { return bulletsRemaining; }

private:
	bool isRight, isLeft;
	Quad* reloadBar;
	
	int hitPoints;

	void LoseInvulnerability();
	TimeInterval* invulnerabilityWindow;
	float invulnerabilityTime;
	bool invulnerable;

	int bulletsRemaining;
	bool reloading;
	float reloadSpeed;

	float maxMoveSpeed;
	float moveSpeed;
};

