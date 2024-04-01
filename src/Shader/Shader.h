#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#ifndef SHADER_H
#define SHADER_H

class Shader{

    public:

        Shader(
            std::string vertexFileName, 
            std::string fragmentFileName
        );

        bool Use();

        GLint getAttribute(std::string name);
        GLint getUniformLocation(std::string name);
        void setUniformMatrix(GLint location, glm::mat4 matrix);

    private:

        std::ifstream vertexFile;
        std::ifstream fragmentFile;

        std::string vertexFileName; 
        std::string fragmentFileName;

        std::stringstream vertexSourceStream;
        std::stringstream fragmentSourceStream;

        std::string vertexSource;
        std::string fragmentSource;

        GLuint vertexShader;
        GLuint fragmentShader;
        GLuint shaderProgram;

        bool ready;
        int Load();
        int Compile();
        int Link();
};



#endif // SHADER_H