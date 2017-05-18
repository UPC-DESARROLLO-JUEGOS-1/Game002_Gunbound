#include "BaseShader.h"
#include "FatalError.h"

#include <fstream>
#include <vector>

BaseShader::BaseShader() :
	programShader_ID(0),
	vertexShader_ID(0),
	fragmentShader_ID(0),
	numAttributes(0)
{
}

BaseShader::~BaseShader()
{
}

void BaseShader::Initialize()
{
	CreateAttributes();
}

void BaseShader::LoadAndCompile(const std::string & vertexShaderFilePath, const std::string & fragmentShaderFilePath)
{
	programShader_ID = glCreateProgram();
	if (programShader_ID == 0) { FatalError("Shader Program couldn't be created"); }
	vertexShader_ID = glCreateShader(GL_VERTEX_SHADER);
	if (vertexShader_ID == 0) {FatalError("Vertex Shader couldn't be created");}
	fragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragmentShader_ID == 0) { FatalError("Fragment Shader couldn't be created"); }

	//Compile
	CompileShader(vertexShaderFilePath, vertexShader_ID);
	CompileShader(fragmentShaderFilePath, fragmentShader_ID);
}

void BaseShader::CompileShader(const std::string & filePath, GLuint shader_ID)
{
	std::ifstream shaderFile(filePath);
	if (shaderFile.fail()) { FatalError("Couldn't open file: " + filePath); }

	std::string fileContents = "";
	std::string line;

	while (std::getline(shaderFile, line)) { fileContents += line + "\n"; }
	shaderFile.close();

	const char* contentsPtr = fileContents.c_str();
	glShaderSource(shader_ID, 1, &contentsPtr, nullptr);
	glCompileShader(shader_ID);

	GLint success = 0;
	glGetShaderiv(shader_ID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader_ID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(shader_ID, maxLength, &maxLength, &(errorLog[0]));
		glDeleteShader(shader_ID);
		std::printf("%s\n", &(errorLog[0]));
		FatalError("Couldn't compile shader: " + filePath);
	}
}

void BaseShader::LinkShaders()
{
	glAttachShader(programShader_ID, vertexShader_ID);
	glAttachShader(programShader_ID, fragmentShader_ID);
	glLinkProgram(programShader_ID);

	GLint isLinked = 0;
	glGetProgramiv(programShader_ID, GL_LINK_STATUS, &isLinked);

	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(programShader_ID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(programShader_ID, maxLength, &maxLength, &(errorLog[0]));
		glDeleteProgram(programShader_ID);
		glDeleteShader(vertexShader_ID);
		glDeleteShader(fragmentShader_ID);
		std::printf("%s\n", &(errorLog[0]));
		FatalError("Shader link failed");
	}

	glDetachShader(programShader_ID, vertexShader_ID);
	glDetachShader(programShader_ID, fragmentShader_ID);
	glDeleteShader(vertexShader_ID);
	glDeleteShader(fragmentShader_ID);
}

GLint BaseShader::GetUniformLocation(const std::string & uniformName)
{
	GLint location = glGetUniformLocation(programShader_ID, uniformName.c_str());
	if (location == GL_INVALID_INDEX) FatalError("Uniform " + uniformName + " wasn't found");
	return location;
}

void BaseShader::AddAttribute(const std::string & attributeName)
{
	glBindAttribLocation(programShader_ID, numAttributes++, attributeName.c_str());
}

void BaseShader::Use()
{
	glUseProgram(programShader_ID);
	for (int i = 0; i < numAttributes; i++) { glEnableVertexAttribArray(i); }
}

void BaseShader::Stop()
{
	glUseProgram(GL_NONE);
	for (int i = 0; i < numAttributes; i++) { glDisableVertexAttribArray(i); }
}