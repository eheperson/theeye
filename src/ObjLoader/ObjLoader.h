#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <glm/glm.hpp>

#include <Drawable.h>
#include <Shader.h>

#ifndef OBJLOADER_H
#define OBJLOADER_H

class ObjLoader : public Drawable{
    
    public:
        ObjLoader(Shader* shader, std::string fileName);

    private:
        void HandleVertexData(std::string type, float x, float y, float z);
        void HandleFaceData(std::string triplet);

        GLint positionAttribute;
        GLint uvAttribute;
        GLint colorAttribute;

        std::vector<float> verticies;
        std::vector<float> uvs;

        std::vector<float> finalData;    
        std::vector<unsigned int> elements;

        std::unordered_map<std::string, unsigned int> elementsCache;

        unsigned int elementID;
};

#endif