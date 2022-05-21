#include<glad/glad.h>

#include "RoomCube.h"

GLfloat roomVerticies[] = { // vertex data
//    Positions                     Colors
    -10.0f,  0.5f, -10.0f,        1.0f, 0.0f, 0.0f, // top-left-front (datapoint-0 or vertice-0)
     10.0f,  0.5f, -10.0f,        0.0f, 1.0f, 0.0f, // top-right-front (datapoint-1 or vertice-1)
     10.0f, -0.5f, -10.0f,        0.0f, 0.0f, 1.0f, // bottom-right-front (datapoint-2 or vertice-2)
    -10.0f, -0.5f, -10.0f,        1.0f, 1.0f, 1.0f, // bottom-left-front (datapoint-3 or vertice-3)

    -10.0f,  0.5f,  10.0f,        1.0f, 0.0f, 0.0f, // top-left-back (datapoint-4 or vertice-4)
     10.0f,  0.5f,  10.0f,        0.0f, 1.0f, 0.0f, // top-right-back (datapoint-5 or vertice-5)
     10.0f, -0.5f,  10.0f,        0.0f, 0.0f, 1.0f, // bottom-right-back (datapoint-6 or vertice-6)
    -10.0f, -0.5f,  10.0f,        1.0f, 1.0f, 1.0f  // bottom-left-back (datapoint-7 or vertice-7)
};

GLuint roomElements[] = { // element data
    //front wall
    0, 1, 2, 
    2, 3, 0,

    //back wall
    4, 5, 6,
    6, 7, 4,

    //left wall
    4, 0, 3,
    3, 7, 4,

    //right wall
    1, 5, 6,
    6, 2, 1,

    //ceilng
    4, 5, 1,
    1, 0, 4,

    //floor
    7, 6, 2,
    2, 3, 7
};

RoomCube :: RoomCube(Shader* shader) : Drawable() {
    this -> bindVAO();
    this -> loadVerticies(roomVerticies, 48);
    this -> loadElements(roomElements, 36);
    this -> posAtt = shader -> getAttribute("position");
    this -> colAtt = shader -> getAttribute("color");

    glEnableVertexAttribArray(this->posAtt);
    // define any of generic  vertex attribute data
    glVertexAttribPointer(
        this->posAtt, //GLuint index
        3, // GLint size : how many element in position attributes
        GL_FLOAT, // GLenum type
        GL_FALSE, // GLboolean normalized
        6*sizeof(float), // GLstride 
        0 // const GLVoid* pointer
    );

    glEnableVertexAttribArray(this->colAtt);
    // define any of generic  vertex attribute data
    glVertexAttribPointer(
        this->colAtt, //GLuint index
        3, // GLint size
        GL_FLOAT, // GLenum type
        GL_FALSE, // GLboolean normalized
        6*sizeof(float), // GLstride 
        (void*)(3*sizeof(float)) // const GLVoid* pointer
    );
};

RoomCube :: ~RoomCube(){};
