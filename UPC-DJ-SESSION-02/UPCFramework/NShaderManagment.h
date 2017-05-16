#pragma once

#include <map>
#include <iostream>

#include "NBaseShader.h"

class NFramework;

class NShaderManagment
{
public:
	NShaderManagment(NFramework* framework) { mFramework = framework; }
	~NShaderManagment();

	void Initialize();

	template<typename T>
	T* LoadAndGetShader(const std::string& path)  {
		std::map<std::string, NBaseShader*>::iterator mit = mShader.find(path);
		T* result = mit != mShader.end() ? (T*)mit->second : nullptr;

		if (result == nullptr) {
			result = new T();
			result->LoadAndCompile(path + ".vert", path + ".frag");
			result->Initialize();
			result->LinkShaders();

			// lo inserto en el diccionario
			mShader.insert(std::make_pair(path, result));

			std::cout << "Loadede shader: " << path << std::endl;
		}

		return result;
	}

private:
	NFramework* mFramework;
	std::map<std::string, NBaseShader*> mShader;
};

