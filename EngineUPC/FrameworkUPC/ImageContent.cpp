#include "ImageContent.h"
#include "PicoPNG.h"

ImageContent::ImageContent(ContentManager* contentManager) 
	: BaseContent(contentManager)
{
}

ImageContent::~ImageContent() {}

void ImageContent::Initialize()
{
	BaseContent::Initialize(); //super (call parent´s version)
}

void ImageContent::Invalidate() {
	glBindTexture(GL_TEXTURE_2D, imageId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imageData[0]);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void ImageContent::SetPixelAlpha(int x, int y, unsigned char alpha, bool invalidate) {
	int startIndex = (x + (y * width)) * 4;

	if (x < 0 || x > (width - 1) || y < 0 || y > (height - 1)) return;

 	imageData.at(startIndex + 3) = alpha;

	if (invalidate) {
		glBindTexture(GL_TEXTURE_2D, imageId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imageData[0]);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void ImageContent::SetPixel(int x, int y, NColor color, bool invalidate) {
	int startIndex = (x + (y * width)) * 4;

	imageData.at(startIndex + 0) = color.r;
	imageData.at(startIndex + 1) = color.g;
	imageData.at(startIndex + 2) = color.b;
	imageData.at(startIndex + 3) = color.a;

	if (invalidate) {
		glBindTexture(GL_TEXTURE_2D, imageId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imageData[0]);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

NColor ImageContent::GetPixel(int x, int y) {
	int startIndex = (x + (y * width)) * 4;

	NColor result;
	result.r = imageData.at(startIndex + 0);
	result.g = imageData.at(startIndex + 1);
	result.b = imageData.at(startIndex + 2);
	result.a = imageData.at(startIndex + 3);

	return result;
}

bool ImageContent::Load(const std::string path)
{
	BaseContent::Load(path);

	std::vector<unsigned char> imageRawBufferData;
	bool fileLoaded = ContentManager::ReadFileToBuffer(path, imageRawBufferData);
	bool imageDecoded = false;

	unsigned long auxWidth;
	unsigned long auxHeight;

	if (fileLoaded)
	{
		imageDecoded = decodePNG(imageData, auxWidth, auxHeight, &(imageRawBufferData[0]), imageRawBufferData.size(), true) == 0;

		width = auxWidth;
		height = auxHeight;

		glGenTextures(1, &imageId);
		glBindTexture(GL_TEXTURE_2D, imageId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imageData[0]);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	return fileLoaded && imageDecoded;
}
