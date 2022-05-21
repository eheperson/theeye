#include <glad/glad.h>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/transform.hpp>
// #include<Shader.h>
#include "Camera.h"


Camera :: Camera(Shader* shader, float w, float h){
    this->shader = shader;
    this->vpUniform = this->shader->getUniformLocation("mvpMatrix");
    this->projectMatrix = glm::perspective(glm::radians(45.0f), w / h, 0.01f, 1000.0f);
};

void Camera :: SetShader(Shader* shader){
    this->shader;
    this->vpUniform = this->shader->getUniformLocation("mvpMatrix"); 
};


void Camera :: SetTranslation(float x, float y, float z){
    // 5,5,5 -> SetTranslation(0,0,0) = 0,0,0
    this->translation = glm::translate(glm::mat4(1.0f), glm::vec3(-x,-y,-z));
    this->UpdateViewMatrix();
};

void Camera :: Translate(float x, float y, float z){
    // 5,5,5 -> Translate(2,0,0) = 7,5,5
    this->translation = glm::translate(this->translation, glm::vec3(-x,-y,-z));
    this->UpdateViewMatrix();
};

void Camera :: SetRotation(float rotation, float x, float y, float z){
    this->rotation = glm::rotate(glm::mat4(1.0f),glm::radians(rotation), glm::vec3(-x,-y,-z));
    this->UpdateViewMatrix();
};

void Camera :: Rotate(float rotation, float x, float y, float z){
    this->rotation = glm::rotate(this->rotation,glm::radians(rotation), glm::vec3(-x,-y,-z));
    this->UpdateViewMatrix();
};

void Camera :: Update(){
    this->shader->setUniformMatrix(this->vpUniform, this->projectMatrix * this->viewMatrix);
};

void Camera :: UpdateViewMatrix(){

    // if only translation applied use this : 
    // this->viewMatrix = this->translation;

    // // if only rotation applied use this : 
    // this->viewMatrix = this->rotation;

    // if translation and rotation applied  and
    // if you want to rotate camera
    // use this : 
    this->viewMatrix = this->rotation * this->translation;

    // if translation and rotation applied  and
    // if you want to rotate object
    // use this : 
    // this->viewMatrix = this->translation * this->rotation;

};