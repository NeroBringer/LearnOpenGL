#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D screenTexture;

void main()
{
    color =  texture(screenTexture, vec2(-1.0,-1.0)); 
}