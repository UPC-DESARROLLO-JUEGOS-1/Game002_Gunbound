#include "NBaseShader.h"
#include "FatalError.h"

#include <fstream>
#include <vector>

NBaseShader::NBaseShader() :
	mProgramShader_ID(0),
	mVertexShader_ID(0),
	mFragmentShader_ID(0),
	mNumAttributes(0)
{
}

NBaseShader::~NBaseShader()
{
}

void NBaseShader::Initialize() {
	CreateAttributes();
}

void NBaseShader::Use() {
	glUseProgram(mProgramShader_ID);

	for (int i = 0; i < mNumAttributes; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void NBaseShader::Unuse() {
	glUseProgram(0);

	for (int i = 0; i < mNumAttributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

GLint NBaseShader::GetUniformLocation(const std::string& uniformName) {
	GLint location = glGetUniformLocation(mProgramShader_ID, uniformName.c_str());

	if (location == GL_INVALID_INDEX) {
		FatalError("El uniform: " + uniformName + " no se encontro en el Shader.");
	}

	return location;
}

void NBaseShader::AddAttribute(const std::string& attributeName) {
	glBindAttribLocation(mProgramShader_ID, mNumAttributes++, attributeName.c_str());
}

void NBaseShader::LoadAndCompile(const std::string& vertexShaderFilePath,
	const std::string fragmentShaderFilePath) {

	mProgramShader_ID = glCreateProgram();
	if (mProgramShader_ID == 0) { FatalError("Program Shader no se pudo crear!"); }

	mVertexShader_ID = glCreateShader(GL_VERTEX_SHADER);
	if (mVertexShader_ID == 0) { FatalError("Vertex Shader no se pudo crear!"); }

	mFragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);
	if (mFragmentShader_ID == 0) { FatalError("Fragment Shader no se pudo crear!"); }

	// Compile
	CompileShader(vertexShaderFilePath, mVertexShader_ID);
	CompileShader(fragmentShaderFilePath, mFragmentShader_ID);
}

void NBaseShader::CompileShader(const std::string& filePath, GLuint shader_ID) {
	std::ifstream shaderFile(filePath);

	if (shaderFile.fail()) {
		FatalError("No se pudo abrir el archivo " + filePath);
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(shaderFile, line)) {
		fileContents += line + "\n";
	}

	shaderFile.close();

	const char* contentsPtr = fileContents.c_str();
	glShaderSource(shader_ID, 1, &contentsPtr, nullptr);
	glCompileShader(shader_ID);

	GLint success = 0;
	glGetShaderiv(shader_ID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {
		GLint maxLenght = 0;
		glGetShaderiv(shader_ID, GL_INFO_LOG_LENGTH, &maxLenght);

		std::vector<char> errorLog(maxLenght);
		glGetShaderInfoLog(shader_ID, maxLenght, &maxLenght, &errorLog[0]);

		glDeleteShader(shader_ID);

		std::printf("%s\n", &(errorLog[0]));
		FatalError("Shader: " + filePath + " fallo en compilar!");
	}
}

void NBaseShader::LinkShaders() {
	glAttachShader(mProgramShader_ID, mVertexShader_ID);
	glAttachShader(mProgramShader_ID, mFragmentShader_ID);

	// aqui se unen
	glLinkProgram(mProgramShader_ID);

	GLint isLinked = 0;
	glGetProgramiv(mProgramShader_ID, GL_LINK_STATUS, &isLinked);

	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(mProgramShader_ID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(mProgramShader_ID, maxLength, &maxLength, &errorLog[0]);

		glDeleteProgram(mProgramShader_ID);
		glDeleteShader(mVertexShader_ID);
		glDeleteShader(mFragmentShader_ID);

		std::printf("%s\n", &(errorLog[0]));
		FatalError("Shader fallo la union(link).");
	}

	glDetachShader(mProgramShader_ID, mVertexShader_ID);
	glDetachShader(mProgramShader_ID, mFragmentShader_ID);
	glDeleteShader(mVertexShader_ID);
	glDeleteShader(mFragmentShader_ID);
}