#include<glad/glad.h>

#include "Shader.h"

Shader :: Shader(std::string vertexFileName, std::string fragmentFileName){
    this->ready = false;
    this->vertexFileName = vertexFileName;
    this->fragmentFileName = fragmentFileName;
    if(this->Load() < 1){
        std::cout << "Error loading shader sources";
        return;
    };
    if(this->Compile() < 1){
        std::cout << "Error loading shader sources";
        return;
    };
    if(this->Link() < 1){
        std::cout << "Error linking shader program";
        return;
    };
    this->ready = true;
};

bool Shader :: Use(){
    if(this->ready){
        glUseProgram(this->shaderProgram);
    };
    return this->ready;
};

int Shader :: Load(){
    this->vertexFile.open(this->vertexFileName, std::ios::in);
    if(!vertexFile)
        return -1;
    this->vertexSourceStream << vertexFile.rdbuf();
    
    this->fragmentFile.open(this->fragmentFileName, std::ios::in);
    if(!fragmentFile)
        return -2;
    this->fragmentSourceStream << fragmentFile.rdbuf();

    this->vertexSource = this->vertexSourceStream.str();
    this->fragmentSource = this->fragmentSourceStream.str();

    return 1;
};

int Shader :: Compile(){

    GLint compiled;
    const char* tempSource;
    
    // Compiling vertex shader --------------- Begin
    tempSource = this->vertexSource.c_str();
    this->vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // replace source code in a shader object
    glShaderSource(this->vertexShader, 1, &tempSource, 0);

    // compile vertex  shader
    glCompileShader(this->vertexShader);

    // return a parameter from shader object
    glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &compiled);

    if(compiled == false){
        unsigned int maxLength;
        glGetShaderiv(this->vertexShader, GL_INFO_LOG_LENGTH, (GLint*)&maxLength);
        char* vertexCompileLog = (char*)malloc(maxLength);
        // Return the information log for a shader object
        glGetShaderInfoLog(this->vertexShader, maxLength, (GLsizei*)&maxLength, vertexCompileLog);
        std::cout << "Vertex shared error : " << std::endl << vertexCompileLog << std::endl << std::endl;
        free(vertexCompileLog);
        return -1;
    };
    // Compiling vertex shader --------------- End

    // Compiling fragment shader --------------- Begin
    tempSource = this->fragmentSource.c_str();
    this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // replace source code in a shader object
    glShaderSource(this->fragmentShader, 1, &tempSource, 0);

    // compile vertex  shader
    glCompileShader(this->fragmentShader);

    // return a parameter from shader object
    glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &compiled);

    if(compiled == false){
        unsigned int maxLength;
        glGetShaderiv(this->fragmentShader, GL_INFO_LOG_LENGTH, (GLint*)&maxLength);
        char* fragmentCompileLog = (char*)malloc(maxLength);
        // Return the information log for a shader object
        glGetShaderInfoLog(this->fragmentShader, maxLength, (GLsizei*)&maxLength, fragmentCompileLog);
        std::cout << "Fragment shared error : " << std::endl << fragmentCompileLog << std::endl << std::endl;
        free(fragmentCompileLog);
        return -2;
    };
    // Compiling fragment shader --------------- End

    return 1;
};

int Shader :: Link(){
    this->shaderProgram = glCreateProgram();

    glAttachShader(this->shaderProgram, this->vertexShader);
    glAttachShader(this->shaderProgram, this->fragmentShader);
    glLinkProgram(this->shaderProgram);

    GLint linked;

    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &linked);
    if(linked == false){
        unsigned int maxLength;
        glGetProgramiv(this->shaderProgram, GL_INFO_LOG_LENGTH, (GLint*)&maxLength);
        char* programLinkLog = (char*)malloc(maxLength);
        glGetShaderInfoLog(this->shaderProgram, maxLength, (GLsizei*)&maxLength, programLinkLog);
        std::cout << "Fragment shared error : " << std::endl << programLinkLog << std::endl << std::endl;
        free(programLinkLog);
        return -1;
    };
    return 1;
};