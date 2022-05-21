#version 150 core

in vec3 Color;
in vec2 uvs;

out vec4 outColor;

uniform bool hasTexture;

uniform sampler2D in_texture;

void main(){
    vec3 tempColor = Color;
    if(hasTexture == true){
        tempColor *= texture(in_texture, uvs).rgb;
    }else{
        tempColor += texture(in_texture, uvs).rgb;
    }
    outColor = vec4(tempColor, 1.0);
    //outColor = vec4(texture(in_texture, uvs).rgb, 1.0);
};