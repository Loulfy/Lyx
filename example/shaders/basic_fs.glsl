#version 400 core

//in vec3 colour;
//in vec2 tex;

out vec4 vColor;

//uniform sampler2D u_texture;

void main()
{
    //vColor = vec4(colour, 1.0) * texture2D(u_texture, tex);
    vColor = vec4(1.0, 0.0, 0.0, 0.0);
}
