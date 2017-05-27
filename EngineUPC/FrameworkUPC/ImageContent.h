#pragma once

#include <vector>
#include <GL\glew.h>
#include "BaseContent.h"
#include "ContentManager.h"
#include "NColor.h"

class ImageContent : public BaseContent
{
public:
	ImageContent(ContentManager* contentManager);
	~ImageContent();

	int GetWidth() { return width; }
	int GetHeight() { return height; }
	GLuint GetTextureId() { return imageId; }

	void Initialize();
	bool Load(const std::string path);

	void Invalidate();
	void SetPixel(int x, int y, NColor color, bool invalidate = true);
	void SetPixelAlpha(int x, int y, unsigned char alpha, bool invalidate);
	NColor GetPixel(int x, int y);
private:
	std::vector<unsigned char> imageData;
	int width;
	int height;
	GLuint imageId;
};

