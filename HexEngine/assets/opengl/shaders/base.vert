#version 330 core
layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec3 a_Color;

uniform vec2 u_Resolution;

out vec3 v_Color;

void main()
{
	vec2 ndc = (a_Position.xy / u_Resolution) * 2.0 - 1.0;
	float ndcZ = (a_Position.z / 100.0) * 2.0 - 1.0;

	gl_Position = vec4(ndc.x, -ndc.y, ndcZ, 1.0);
	v_Color = a_Color;
}