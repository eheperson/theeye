
#include <glad/glad.h>
#include "ObjLoader.h"


ObjLoader :: ObjLoader(Shader* shader, std::string fileName) : Drawable() {
    
    std::ifstream file;
    std::stringstream dataStream;
    
    this->elementID = 0;

    file.open(fileName, std::ios::in);

    if(file){
    
        std::string line;
    
        while(std::getline(file, line)){
    
            std::istringstream stringStream(line.substr(1));
            
            switch (line[0]){
                case '#':
                    break;

                case 'v':
                    float x, y, z;
                    stringStream >> x >> y >> z;
                    this->HandleVertexData(line, x, y, z);
                    break;

                case 'f':
                    std::string triplet;
                    while(stringStream >> triplet){
                        this->HandleFaceData(triplet);
                    };
                    break;
            }
        };

        this->bindVAO();
        this->loadVerticies(this->finalData);
        this->loadElements(this->elements);

        this -> positionAttribute = shader->getAttribute("position");
        this -> colorAttribute = shader -> getAttribute("color");
        this -> uvAttribute = shader-> getAttribute("uv");

        glEnableVertexAttribArray(this->positionAttribute);
        // define any of generic  vertex attribute data
        glVertexAttribPointer(
            this->positionAttribute, //GLuint index
            3, // GLint size
            GL_FLOAT, // GLenum type
            GL_FALSE, // GLboolean normalized
            8*sizeof(float), // GLstride 
            0 // const GLVoid* pointer
        );

        glEnableVertexAttribArray(this->colorAttribute);
        // define any of generic  vertex attribute data
        glVertexAttribPointer(
            this->colorAttribute, //GLuint index
            3, // GLint size
            GL_FLOAT, // GLenum type
            GL_FALSE, // GLboolean normalized
            8*sizeof(float), // GLstride 
            (void*)(3*sizeof(float)) // const GLVoid* pointer
        );

        glEnableVertexAttribArray(this->uvAttribute);
        // define any of generic  vertex attribute data
        glVertexAttribPointer(
            this->uvAttribute, //GLuint index
            2, // GLint size
            GL_FLOAT, // GLenum type
            GL_FALSE, // GLboolean normalized
            8*sizeof(float), // GLstride 
            (void*)(6*sizeof(float)) // const GLVoid* pointer
        );

        this->unbindVAO();

        this->verticies.clear();
        this->uvs.clear();
        this->finalData.clear();
        this->elements.clear();
        this->elementsCache.clear();
        dataStream.clear();
        file.close();

    };
};


void ObjLoader :: HandleVertexData(std::string type, float x, float y, float z){
    switch (type[1]){
        case 't' :
            this->uvs.push_back(x);
            this->uvs.push_back(y);
            break;

        case ' ' :
            this->verticies.push_back(x);
            this->verticies.push_back(y);
            this->verticies.push_back(z);
            break;
    };
};


void ObjLoader :: HandleFaceData(std::string triplet){
    float v, vt, vn;
    
    std::istringstream stringStream(triplet);
    std::string token;

    std::getline(stringStream, token,  '/');
    v = std::stoul(token, 0, 10);

    std::getline(stringStream, token,  '/');
    vt = std::stoul(token, 0, 10);

    std::getline(stringStream, token,  '/');
    vn = std::stoul(token, 0, 10);

    v -= 1;
    vt -= 1;
    vn -= 1;

    std::string elementString = std::to_string(v) + std::to_string(vt) + std::to_string(vn);
    
    auto element = this->elementsCache.find(elementString);
    
    if(element != this->elementsCache.end()){

        this->elements.emplace_back(element->second);
    
    }else{
        
        for(int i = 0;  i < 3; i++){
            this->finalData.emplace_back(this->verticies[v*3 + i]);
        };
        
        this->finalData.emplace_back(this->elementID / 256.0f);
        this->finalData.emplace_back(1);
        this->finalData.emplace_back(1);
        
        for(int i = 0;  i<2; i++){
            this->finalData.emplace_back(this->uvs[vt*2 + i]);
        };
        this->elements.emplace_back(this->elementID);
        this->elementsCache.emplace(elementString, this->elementID);
        this->elementID += 1;
    };
};