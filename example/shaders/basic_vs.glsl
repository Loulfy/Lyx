#version 400 core

layout(location = 0) in vec2 Position;
//layout(location = 1) in vec3 Color;
//layout(location = 2) in vec2 TexCoord;

//out vec3 colour;
//out vec2 tex;

//uniform mat4 u_projView;

void main()
{  
    //colour = Color;
    //tex = TexCoord;
    gl_Position = vec4(Position, 0.0, 1.0);
}

