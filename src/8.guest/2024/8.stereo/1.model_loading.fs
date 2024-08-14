#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 FragWorldPos;

uniform vec4 cursorPos;
uniform sampler2D texture_diffuse1;

void main()
{    
    FragColor = texture(texture_diffuse1, TexCoords);

    if(cursorPos.w > 0) {
        float distanceToCursor = length(cursorPos.xyz - FragWorldPos);

        float outerRadius = 0.08; 
        float outerBorderThickness = 0.01;
        float innerRadius = 0.004;
        float innerBorderThickness = 0.005;
        float tOuter = 1.0 - smoothstep(0.0, outerBorderThickness, abs(outerRadius - distanceToCursor));
        float tInner = 1.0 - smoothstep(0.0, innerBorderThickness, abs(innerRadius - distanceToCursor));
        vec4 inner = mix(FragColor, vec4(1.0, 1.0, 1.0, 0.5), tInner);
        FragColor = mix(inner, vec4(1.0, 1.0, 1.0, 1.0), tOuter);
    }
}