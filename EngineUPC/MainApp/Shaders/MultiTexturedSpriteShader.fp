#version 130

in vec4 fragmentColor;
in vec2 fragmentUV;

out vec4 color;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
	vec4 base=texture(tex0, fragmentUV);
	vec4 negative=vec4(vec3(1.0)-texture(tex0, fragmentUV).xyz, texture(tex0, fragmentUV).w);
	
	float current=texture(tex1, fragmentUV).w;
	vec3 posColor=vec3(1-current)*base.xyz+vec3(current)*negative.xyz;
	color = vec4(posColor, base.w);
}