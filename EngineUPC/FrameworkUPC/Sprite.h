#pragma once

#include "ImageContent.h"
#include "Drawable2D.h"

#include <string>

class Sprite : public Drawable2D
{
public:
	Sprite() :
		pivot(0.0f, 0.0f)
	{}
	~Sprite()
	{
		content = nullptr;
		Drawable2D::~Drawable2D();
	}

	int GetWidth() { return width; }
	int GetHeight() { return height; }
	int GetVisibleWidth() { return width*scale.x; }
	int GetVisibleHeight() { return height*scale.y; }

	void Initialize(float x, float y, const std::string path);
	void Update(float dt);
	void Draw(float dt);

	void SetColor(float r, float g, float b, float a);
	void SetPivot(float x, float y);
	void SetPivot(float value);

protected:
	int width, height;
	int r, g, b, a;
	ImageContent* content;
	Vector2 pivot;

	void BindData();
};

