#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 tc;

out float Height;
out vec3 Position;

uniform sampler2D heightMap;
/* on cpu we used:
float yScale = 64.0f / 256.0f, yShift = 16.0f;
vertices.push_back( -height/2.0f + height*i/(float)height );   // vx
vertices.push_back( (int) y * yScale - yShift);   // vy
vertices.push_back( -width/2.0f + width*j/(float)width );   // vz
*/

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{ 
    float yScale = 64.0; // originally: 256.0 from texture * 64.0 / 256.0;
    float yShift = 16.0;
    Height = textureLod(heightMap,tc,0.0).x;
    vec3 displacedPos = vec3(aPos.x, Height * yScale - yShift, aPos.z);
    gl_Position = projection * view * model * vec4(displacedPos, 1.0);
}