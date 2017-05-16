#include "NImageContent.h"
#include "NContentManagement.h"
#include "PicoPNG.h"

NImageContent::NImageContent(NContentManagement* contentManagement) :
	NBaseContent(contentManagement) {

}

NImageContent::~NImageContent()
{
}

void NImageContent::Initialize() {
	NBaseContent::Initialize();
}

bool NImageContent::Load(const std::string path) {
	NBaseContent::Load(path);

	std::vector<unsigned char> imageRawBufferData;
	bool fileLoaded = NContentManagement::ReadFileToBuffer(mPath,
		imageRawBufferData);
	bool imageDecoded = false;

	unsigned long rWidth;
	unsigned long rHeight;

	if (fileLoaded) {
		int decodedResult = decodePNG(mImageData, rWidth, rHeight,
			&(imageRawBufferData[0]), imageRawBufferData.size(),
			true);
		imageDecoded = decodedResult == 0;

		// Una vez cargado la imagen, se lo paso al OpenGL a 
		// procesar...
		mWidth = rWidth;
		mHeight = rHeight;

		glGenTextures(1, &mImageId);

		glBindTexture(GL_TEXTURE_2D, mImageId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL_POINT, para pixel art
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_POINT
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, &(mImageData[0]));

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	return fileLoaded && imageDecoded;
}