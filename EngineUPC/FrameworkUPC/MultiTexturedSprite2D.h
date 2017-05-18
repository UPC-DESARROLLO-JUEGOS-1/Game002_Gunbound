#pragma once

#include "ImageContent.h"
#include "Drawable2D.h"

#include <string>

class MultiTexturedSprite2D : public Drawable2D
{
public:
	MultiTexturedSprite2D() {}
	~MultiTexturedSprite2D()
	{
		content1 = nullptr;
		content2 = nullptr;
		Drawable2D::~Drawable2D();
	}

	int GetWidth() { return width; }
	int GetHeight() { return height; }
	int GetVisibleWidth() { return width*scale.x; }
	int GetVisibleHeight() { return height*scale.y; }

	void Initialize(float x, float y, const std::string path1, const std::string path2);
	void Draw(float dt);

	void SetColor(float r, float g, float b, float a);

protected:
	int width, height;
	ImageContent* content1;
	ImageContent* content2;
	int r, g, b, a;

	void BindData();
};

