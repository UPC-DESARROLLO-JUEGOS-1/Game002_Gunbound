#pragma once

#include <map>
#include <iostream>
#include "BaseShader.h"

class GameFramework;

class ShaderManager
{
public:
	ShaderManager(GameFramework* framework) { this->framework = framework; }
	~ShaderManager();

	void Initialize();

	template<typename T>
	T* LoadAndGetShader(const std::string& path)
	{
		std::map<std::string, BaseShader*>::iterator it = shaders.find(path);
		T* result = it != shaders.end() ? (T*)it->second : nullptr;

		if (result == nullptr)
		{
			result = new T();
			result->LoadAndCompile(path+".vp", path+".fp");
			result->Initialize();
			result->LinkShaders();

			shaders.insert(std::make_pair(path, result));

			std::cout << "Loaded shader: " << path << std::endl;
		}

		return result;
	}

private:
	GameFramework* framework;
	std::map<std::string, BaseShader*> shaders;
};

