#pragma once

#include "NBaseShader.h"

class NSpriteShader : public NBaseShader
{
public:
	NSpriteShader() { NBaseShader::NBaseShader(); }
	~NSpriteShader() { NBaseShader::~NBaseShader(); }

protected:
	void CreateAttributes();
};

