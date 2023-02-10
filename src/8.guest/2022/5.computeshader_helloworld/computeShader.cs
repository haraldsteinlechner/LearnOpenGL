#version 430 core

layout(local_size_x = 8, local_size_y = 10, local_size_z = 1) in;

// ----------------------------------------------------------------------------
//
// uniforms
//
// ----------------------------------------------------------------------------

layout(std430, binding = 1) buffer inputData
{
    float i [];
};

layout(std430, binding = 2) buffer outputData
{
    float o [];
};


void main()
{
    o[gl_GlobalInvocationID.x] = 0;
}