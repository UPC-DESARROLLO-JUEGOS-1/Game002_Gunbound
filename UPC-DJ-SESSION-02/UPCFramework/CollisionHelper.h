#pragma once

#include "NSprite.h"
#include "NPrimitiveQuad.h"

class CollisionHelper
{
public:
	static bool HitTest(NSprite* a, NSprite* b) {
		float xa = a->GetX();
		float xb = b->GetX();
		float ya = a->GetY();
		float yb = b->GetY();
		float wa = a->GetVisibleWidth();
		float wb = b->GetVisibleWidth();
		float ha = a->GetVisibleHeight();
		float hb = b->GetVisibleHeight();

		return
			xa < (xb + wb) && (xa + wa) > xb &&
			ya < (yb + hb) && (ya + ha) > yb;
	}

	static bool HitTest(NPrimitiveQuad* a, NPrimitiveQuad* b) {
		float xa = a->GetX();
		float xb = b->GetX();
		float ya = a->GetY();
		float yb = b->GetY();
		float wa = a->GetVisibleWidth();
		float wb = b->GetVisibleWidth();
		float ha = a->GetVisibleHeight();
		float hb = b->GetVisibleHeight();

		return
			xa < (xb + wb) && (xa + wa) > xb &&
			ya < (yb + hb) && (ya + ha) > yb;
	}

	static bool HitTest(NSprite* a, NPrimitiveQuad* b) {
		float xa = a->GetX();
		float xb = b->GetX();
		float ya = a->GetY();
		float yb = b->GetY();
		float wa = a->GetVisibleWidth();
		float wb = b->GetVisibleWidth();
		float ha = a->GetVisibleHeight();
		float hb = b->GetVisibleHeight();

		return
			xa < (xb + wb) && (xa + wa) > xb &&
			ya < (yb + hb) && (ya + ha) > yb;
	}

	static bool HitTest(NSprite* a, float x, float y) {
		float xa = a->GetX();
		float ya = a->GetY();
		float wa = a->GetVisibleWidth();
		float ha = a->GetVisibleHeight();

		return x > xa && y > ya && x < (xa + wa) && y < (ya + ha);
	}

	static bool HitTest(NPrimitiveQuad* a, float x, float y) {
		float xa = a->GetX();
		float ya = a->GetY();
		float wa = a->GetVisibleWidth();
		float ha = a->GetVisibleHeight();

		return x > xa && y > ya && x < (xa + wa) && y < (ya + ha);
	}
private:
	CollisionHelper() {}
}