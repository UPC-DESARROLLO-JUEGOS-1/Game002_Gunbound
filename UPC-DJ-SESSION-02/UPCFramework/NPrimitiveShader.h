#pragma once

#include "NBaseShader.h"

class NPrimitiveShader : public NBaseShader
{
public:
	NPrimitiveShader() { NBaseShader::NBaseShader(); }
	~NPrimitiveShader() { NBaseShader::~NBaseShader(); }
protected:
	void CreateAttributes();
};
