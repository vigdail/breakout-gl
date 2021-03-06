#version 330 core

in VS_OUT {
    vec4 position;
    vec2 uv;
} fs_in;

out vec4 glColor;

uniform sampler2D image;
uniform vec3 color;

void main() {
    glColor = vec4(color, 1.0) * texture(image, fs_in.uv);
}