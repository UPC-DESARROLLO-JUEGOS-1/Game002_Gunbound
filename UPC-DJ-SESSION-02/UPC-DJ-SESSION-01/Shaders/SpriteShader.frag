#version 130

in vec4 fragmentColor;
in vec2 fragmentUV;

out vec4 pixelResult;

uniform sampler2D sampler;

void main() {
	pixelResult = texture(sampler, fragmentUV) * fragmentColor;
}