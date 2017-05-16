#include "NSpriteShader.h"

void NSpriteShader::CreateAttributes() {
	AddAttribute("vertexPosition");
	AddAttribute("vertexColor");
	AddAttribute("vertexUV");
}