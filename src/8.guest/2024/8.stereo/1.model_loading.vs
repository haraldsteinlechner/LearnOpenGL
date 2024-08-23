#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 FragWorldPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float eye;
uniform float separation;
uniform float convergence;

void main()
{ 
    TexCoords = aTexCoords;    
    vec4 wp = model * vec4(aPos, 1.0);
    vec4 clipPos = projection * view * wp;
    clipPos.x += eye * separation * (clipPos.w - convergence);
    gl_Position = clipPos;
    FragWorldPos = wp.xyz;
}