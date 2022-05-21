#include<SDL2/SDL.h>
#include<glad/glad.h>

#include "TesterModule.h"

GLfloat vData[] = { // vertex data
//   p      p     c     c     c        (p:position,  c:color)
    -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, // top-left
     0.5f, 0.5f, 0.0f, 1.0f, 0.0f, // top-right
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // bottom-right
     -0.5f, -0.5f, 1.0f, 1.0f, 1.0f // bottom-left 
};

GLuint eData[] = { // element data
    0, 1, 2,
    2, 3, 0
};

TestState :: TestState(Application* app) : GameState(app) {};

bool TestState :: Init(){
    glClearColor(1,0,0,1);
    this->shader = new Shader("test_shader.vert", "test_shader.frag");
    this->shader->Use();
    this->testShape = new TestShape(this->shader);
    return true;
};

bool TestState :: Update(){
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    this-testShape->Draw();

    const uint8_t* state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_RIGHT]){
        SetState<TestState2>(this->app);
        std :: cout << "Arrow Key Right" << std :: endl;
    }

    return true;
};

bool TestState :: Destroy(){
    return true;
};

TestState :: ~TestState(){
    delete this->shader;
};


TestState2 :: TestState2(Application* app) : GameState(app){};

bool TestState2 :: Init(){
    glClearColor(0,0,1,1);

    return true;
};

bool TestState2 :: Update(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const uint8_t* state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_LEFT]){
        SetState<TestState>(this->app);
        std :: cout << "Arrow Key Left" << std :: endl;
    }

    return true;
};

bool TestState2 :: Destroy(){
    return true;
};

TestState2 :: ~TestState2(){};

TestShape :: TestShape(Shader* shader) : Drawable() {
    this -> bindVAO();
    this -> loadVerticies(vData, 20);
    this -> loadElements(eData, 6);
    this -> posAtt = shader -> getAttribute("position");
    this -> colAtt = shader -> getAttribute("color");

    glEnableVertexAttribArray(this->posAtt);
    // define any of generic  vertex attribute data
    glVertexAttribPointer(
        this->posAtt, //GLuint index
        2, // GLint size
        GL_FLOAT, // GLenum type
        GL_FALSE, // GLboolean normalized
        5*sizeof(float), // GLstride 
        0 // const GLVoid* pointer
    );

    glEnableVertexAttribArray(this->colAtt);
    // define any of generic  vertex attribute data
    glVertexAttribPointer(
        this->colAtt, //GLuint index
        3, // GLint size
        GL_FLOAT, // GLenum type
        GL_FALSE, // GLboolean normalized
        5*sizeof(float), // GLstride 
        (void*)(2*sizeof(float)) // const GLVoid* pointer
    );
};

TestShape :: ~TestShape(){};
