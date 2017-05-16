#include "NContentManagement.h"
#include "NFramework.h"
#include "NImageContent.h"

void NContentManagement::Initialize() {

}

NContentManagement::~NContentManagement()
{
}

//NImageContent* NContentManagement::LoadImageContent(const std::string) {
	//NImageContent* content = new NImageContent()
//}

bool NContentManagement::ReadFileToBuffer(const std::string filePath,
	std::vector<unsigned char>& buffer) {

	std::ifstream file(filePath, std::ios::binary);

	if (file.fail()) {
		perror(filePath.c_str());
		return false;
	}

	// seek to end
	file.seekg(0, std::ios::end);

	// get file size
	int fileSize = file.tellg();

	// ahora sacar header, estoy poniendo un rango de lectura, 
	// pero todavia no leo
	file.seekg(0, std::ios::beg);
	// resto el tamaño del header
	fileSize -= file.tellg();

	buffer.resize(fileSize);
	file.read((char*)&(buffer[0]), fileSize);
	file.close();

	return true;
}