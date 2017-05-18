#pragma once

#include <GL\glew.h>
#include <string>

class BaseShader
{
public:
	BaseShader();
	~BaseShader();

	GLint GetUniformLocation(const std::string& uniformName);

	virtual void Initialize();
	void LoadAndCompile(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	void LinkShaders();

	virtual void Use();
	virtual void Stop();

private:
	GLuint vertexShader_ID;
	GLuint fragmentShader_ID;
	GLuint programShader_ID;

	void CompileShader(const std::string& filePath, GLuint shader_ID);

protected:
	int numAttributes;
	virtual void CreateAttributes() {}
	void AddAttribute(const std::string& attributeName);
};

