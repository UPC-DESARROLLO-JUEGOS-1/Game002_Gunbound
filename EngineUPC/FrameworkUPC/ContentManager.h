#pragma once

#include <map>
#include <iostream>
#include <type_traits>
#include <vector>
#include <fstream>

#include "BaseContent.h"
#include "ImageContent.h"
class ImageContent;
class GameFramework;

class ContentManager
{
public:
	ContentManager(GameFramework* framework) { this->framework = framework; }
	~ContentManager() {};

	void Initialize();
	template<typename T>
	T* LoadAndGetContent(const std::string path)
	{
		std::map<std::string, BaseContent*>::iterator it = contents.find(path);
		T* result = it != contents.end() ? (T*)it->second : nullptr;
		
		if (result == nullptr)
		{
			result = new T(this);
			result->Initialize();
			result->Load(path);
			contents.insert(std::make_pair(path, result));
			std::cout << "Loaded content: " << path << std::endl;
		}

		return result;
	}
	static bool ReadFileToBuffer(const std::string filePath, std::vector<unsigned char>& buffer);
private:
	GameFramework* framework;
	std::map<std::string, BaseContent*> contents;

	ImageContent* LoadImageContent(const std::string path);
	BaseContent* GetContent(const std::string path)
	{
		std::map<std::string, BaseContent*>::iterator it = contents.find(path);

		if (it == contents.end())
		{
			std::cout << "Content not found in " << path << std::endl;
			return nullptr;
		}

		return it->second;
	}
};