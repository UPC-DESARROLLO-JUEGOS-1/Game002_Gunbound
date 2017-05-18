#pragma once

#include "Sprite.h"
#include "Quad.h"

struct Body
{
	float left;
	float right;
	float top;
	float bottom;
};

class CollisionHelper
{
private:
	CollisionHelper() {}

private: 
	static bool SimpleAABBTest(Body a, Body b)
	{
		if (a.left > b.right) return false;
		if (a.right < b.left) return false;
		if (a.top > b.bottom) return false;
		if (a.bottom < b.top) return false;

		/*
		if ( > b->GetX() + b->GetWidth()) return false;
		if (a->GetX() + a->GetWidth() < b->GetX()) return false;
		if (a->GetY() > b->GetY() + b->GetHeight()) return false;
		if (a->GetY() + a->GetHeight() < b->GetY()) return false;
		*/
		
		return true;
	}

public:
	static bool HitTest(Sprite* a, Sprite* b)
	{
		Body bodyA;
		Vector2 posA = a->GetPosition();
		bodyA.left = posA.x;
		bodyA.right = posA.x + a->GetWidth();
		bodyA.top = posA.y;
		bodyA.bottom = posA.y + a->GetHeight();

		Body bodyB;
		Vector2 posB = b->GetPosition();
		bodyB.left = posB.x;
		bodyB.right = posB.x + b->GetWidth();
		bodyB.top = posB.y;
		bodyB.bottom = posB.y + b->GetHeight();

		return SimpleAABBTest(bodyA, bodyB);
	}

	static bool HitTest(Quad* a, Sprite* b)
	{
		Body bodyA;
		Vector2 posA = a->GetPosition();
		bodyA.left = posA.x;
		bodyA.right = posA.x + a->GetWidth();
		bodyA.top = posA.y;
		bodyA.bottom = posA.y + a->GetHeight();

		Body bodyB;
		Vector2 posB = b->GetPosition();
		bodyB.left = posB.x;
		bodyB.right = posB.x + b->GetWidth();
		bodyB.top = posB.y;
		bodyB.bottom = posB.y + b->GetHeight();

		return SimpleAABBTest(bodyA, bodyB);
	}

	static bool HitTest(Quad* a, Quad* b)
	{
		Body bodyA;
		Vector2 posA = a->GetPosition();
		bodyA.left = posA.x;
		bodyA.right = posA.x + a->GetWidth();
		bodyA.top = posA.y;
		bodyA.bottom = posA.y + a->GetHeight();

		Body bodyB;
		Vector2 posB = b->GetPosition();
		bodyB.left = posB.x;
		bodyB.right = posB.x + b->GetWidth();
		bodyB.top = posB.y;
		bodyB.bottom = posB.y + b->GetHeight();

		return SimpleAABBTest(bodyA, bodyB);
	}

	static bool PointTest(float x, float y, Sprite* a)
	{
		Vector2 pos = a->GetPosition();
		if (x < pos.x) return false;
		if (x > pos.x + a->GetWidth()) return false;
		if (y < pos.y) return false;
		if (y > pos.y + a->GetHeight()) return false;
		return true;
	}
};

