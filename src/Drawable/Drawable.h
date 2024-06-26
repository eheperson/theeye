#include<vector>
#include<iterator>
#include<SDL3/SDL.h>



#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable{
    private:
        GLuint vao; // vertex array object
        GLuint vbo; // vertex buffer object
        GLuint ebo; // element buffer object

        std::vector<GLuint> elements;
        std::vector<float> verticies;

        GLuint textureID;
        SDL_Surface* texture;

    protected:
        void loadVerticies(float data[], size_t size);
        void loadVerticies(std::vector<float> data);

        void loadElements(GLuint data[], size_t size);
        void loadElements(std::vector<GLuint> data);

        void loadTexture(std::string fileName);

        void bindVAO();
        void unbindVAO();

    public:
        Drawable();
        bool Draw();
        ~Drawable();
};


#endif