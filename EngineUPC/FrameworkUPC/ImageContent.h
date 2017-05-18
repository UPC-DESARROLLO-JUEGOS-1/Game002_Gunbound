#pragma once

#include <vector>
#include <GL\glew.h>
#include "BaseContent.h"
#include "ContentManager.h"

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
private:
	std::vector<unsigned char> imageData;
	int width;
	int height;
	GLuint imageId;
};

