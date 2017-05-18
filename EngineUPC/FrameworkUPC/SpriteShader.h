#pragma once

#include "BaseShader.h"
#include "VertexData.h"
#include "Vector2.h"

struct DataSpriteVertex
{
	Position Position;
	Color Color;
	UV UV;

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

	void SetUV(float u, float v)
	{
		UV.u = u;
		UV.v = v;
	}
};

class SpriteShader : public BaseShader
{
public:
	SpriteShader() { BaseShader::BaseShader(); }
	~SpriteShader() { BaseShader::~BaseShader(); }

protected:
	void CreateAttributes()
	{
		AddAttribute("vertexPosition");
		AddAttribute("vertexColor");
		AddAttribute("vertexUV");
	}
};