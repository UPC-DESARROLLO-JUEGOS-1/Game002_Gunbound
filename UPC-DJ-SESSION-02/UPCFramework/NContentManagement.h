#pragma once

#include <map>
#include <iostream>
#include <type_traits>
#include <vector>
#include <fstream>

#include "NBaseContent.h"
#include "NImageContent.h"

class NFramework;

class NContentManagement
{
public:
	NContentManagement(NFramework* framework) { mFramework = framework; }
	~NContentManagement();

	void Initialize();

	template<typename T>
	T* LoadAndGetContent(const std::string path) {
		std::map<std::string, NBaseContent*>::iterator mit = mContents.find(path);
		T* result = mit != mContents.end() ? (T*)mit->second : nullptr;

		if (result == nullptr) {
			result = new T(this);
			result->Initialize();
			result->Load(path);

			// Ahora insertamos en el mapa(diccionario)
			mContents.insert(std::make_pair(path, result));

			std::cout << "Loaded content: " << path << std::endl;
		}

		return result;
	}
	
	static bool ReadFileToBuffer(const std::string filePath, 
		std::vector<unsigned char>& buffer);
private:
	NFramework* mFramework;
	std::map<std::string, NBaseContent*> mContents;

	NImageContent* LoadImageContent(const std::string path);

	NBaseContent* GetContent(const std::string path) {
		std::map<std::string, NBaseContent*>::iterator mit = mContents.find(path);

		if (mit == mContents.end()) {
			std::cout << "No se encontro el contenido en: " << path;
			return nullptr;
		}

		return mit->second;
	}
};

