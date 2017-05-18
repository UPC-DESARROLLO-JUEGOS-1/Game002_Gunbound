#pragma once

#include "BaseShader.h"
#include "VertexData.h"
#include "Vector2.h"

struct DataPrimitiveVertex
{
	Position Position;
	Color Color;

	void SetPosition(float x, float y)
	{
		Position.x = x;
		Position.y = y;
	}

	void SetColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
	{
		Color.r = r;
		Color.g = g;
		Color.b = b;
		Color.a = a;
	}

	static int GetSize()
	{
		return (sizeof(float) * 2 + sizeof(GLubyte) * 4);
	}
};

class PrimitiveShader : public BaseShader
{
public:
	PrimitiveShader() { BaseShader::BaseShader(); }
	~PrimitiveShader() { BaseShader::~BaseShader(); }

protected:
	void CreateAttributes()
	{
		AddAttribute("vertexPosition");
		AddAttribute("vertexColor");
	}
};

