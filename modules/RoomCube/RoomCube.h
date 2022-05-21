#include<Drawable.h>
#include<Shader.h>

#ifndef ROOMCUBE_H
#define ROOMCUBE_H

class RoomCube  : public Drawable {
    private:
        GLint posAtt; //position attribute
        GLint colAtt; // color attribute 
    public:
        RoomCube(Shader* shader);
        ~RoomCube();
};

#endif