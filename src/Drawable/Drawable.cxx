#include<glad/glad.h>

#include "Drawable.h"

Drawable :: Drawable(){
    this->vao = 0;
    this->vbo = 0;
    this->ebo = 0;

    this->textureID = 0;

    glGenVertexArrays(1, &this->vao);
};

void Drawable :: loadVerticies(float data[], size_t size){
    this->verticies.insert(this->verticies.end(), data, data+size);

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    // create and initialize a buffer object's data store
    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(GLfloat)*this->verticies.size(), 
        this->verticies.data(), 
        GL_STATIC_DRAW
    );
};

void Drawable :: loadVerticies(std::vector<float> data){
    this->verticies.insert(this->verticies.end(), data.begin(), data.end());

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    // create and initialize a buffer object's data store
    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(GLfloat)*this->verticies.size(), 
        this->verticies.data(), 
        GL_STATIC_DRAW
    );
};

void Drawable :: loadElements(GLuint data[], size_t size){
    this->elements.insert(this->elements.end(), data, data+size);

    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        sizeof(GLuint)*this->elements.size(),
        this->elements.data(),
        GL_STATIC_DRAW
    );
};

void Drawable :: loadElements(std::vector<GLuint> data){
    this->elements.insert(this->elements.end(), data.begin(), data.end());

    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        sizeof(GLuint)*this->elements.size(),
        this->elements.data(),
        GL_STATIC_DRAW
    );
};

void Drawable :: loadTexture(std::string fileName){
    this->texture = SDL_LoadBMP(fileName.c_str());
    if(this->texture){
        glGenTextures(1, &this->textureID);
        // glGenTextures(15, <list_of_textures>;

        if(this->textureID){

            glBindTexture(GL_TEXTURE_2D, this->textureID);

            // specify a 2 dimensional texture image
            glTexImage2D(
                GL_TEXTURE_2D, 
                0, 
                GL_RGB, 
                this->texture->w, 
                this->texture->h, 
                0, 
                GL_BGR,
                GL_UNSIGNED_BYTE,
                this->texture->pixels
            );

            // set texture parameters
            glTexParameteri(
                GL_TEXTURE_2D,
                GL_TEXTURE_MIN_FILTER,
                GL_LINEAR_MIPMAP_LINEAR // GL_NEAREST
            );

            // set texture parameters
            glTexParameteri(
                GL_TEXTURE_2D,
                GL_TEXTURE_MAG_FILTER,
                GL_LINEAR // GL_NEAREST
            );

            GLfloat largestAnisotropy;
            glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &largestAnisotropy);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, largestAnisotropy);

            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);
        };
    };
};

void Drawable :: bindVAO(){
    glBindVertexArray(this->vao);
};

void Drawable :: unbindVAO(){
    glBindVertexArray(0);
};

bool Drawable :: Draw(){
    if(!this->vao || !this->vbo || !this->ebo){
        return false;
    };
    this->bindVAO();

    glBindTexture(GL_TEXTURE_2D, this->textureID);

    // render primitives from arraya data
    glDrawElements(
        GL_TRIANGLES,
        this->elements.size(),
        GL_UNSIGNED_INT,
        0
    );
    glBindTexture(GL_TEXTURE_2D, 0);
    this->unbindVAO();
    return true;
};

Drawable :: ~Drawable(){
    if(this->ebo){
        glDeleteBuffers(1, &this->ebo);
    };
    if(this->vbo){
        glDeleteBuffers(1, &this->vbo);
    };
    if(this->vao){
        glDeleteVertexArrays(1, &this->vao);
    };
    if(this->textureID){
        SDL_FreeSurface(this->texture);
    };
};