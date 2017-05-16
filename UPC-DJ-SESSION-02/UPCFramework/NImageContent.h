#pragma once

#include <vector>
#include <GL/glew.h>

#include "NBaseContent.h"

class NImageContent : public NBaseContent
{
public:
	NImageContent(NContentManagement* contentManagement);
	~NImageContent();

	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
	GLuint GetTextureId() { return mImageId; }

	void Initialize();
	bool Load(const std::string path);

private:
	std::vector<unsigned char> mImageData;
	int mWidth;
	int mHeight;
	GLuint mImageId;
};

