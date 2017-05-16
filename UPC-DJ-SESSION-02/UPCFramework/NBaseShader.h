#pragma once

#include <GL/glew.h>
#include <string>

class NBaseShader
{
public:
	NBaseShader();
	~NBaseShader();

	GLint GetUniformLocation(const std::string& uniformName);

	virtual void Initialize();
	void LoadAndCompile(const std::string& vertexShaderFilePath,
		const std::string fragmentShaderFilePath);
	void LinkShaders();

	virtual void Use();
	virtual void Unuse();

private:
	GLuint mVertexShader_ID;
	GLuint mFragmentShader_ID;
	GLuint mProgramShader_ID;

	void CompileShader(const std::string& filePath, GLuint shader_ID);

protected:
	int mNumAttributes;

	virtual void CreateAttributes() {}
	void AddAttribute(const std::string& attributeName);
};

