#pragma once

#include "ImageContent.h"
#include "Drawable2D.h"

#include <string>

class Sprite : public Drawable2D
{
public:
	Sprite() {}
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

protected:
	int width, height;
	int r, g, b, a;
	ImageContent* content;

	void BindData();
};

