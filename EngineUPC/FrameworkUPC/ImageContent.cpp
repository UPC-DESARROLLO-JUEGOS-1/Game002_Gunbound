#include "ImageContent.h"
#include "PicoPNG.h"

ImageContent::ImageContent(ContentManager* contentManager) : BaseContent(contentManager)
{
}

ImageContent::~ImageContent() {}

void ImageContent::Initialize()
{
	BaseContent::Initialize(); //super (call parent´s version)
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
