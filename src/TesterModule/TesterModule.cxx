#include<SDL3/SDL.h>
#include<glad/glad.h>

#include "TesterModule.h"

TestState :: TestState(Application* app) : GameState(app) {};

bool TestState :: Init(){
    glClearColor(1,0,0,1);
    this->shader = new Shader("test_shader.vert", "test_shader.frag");
    this->shader->Use();
    this->hasTextureUniform =  this->shader->getUniformLocation("hasTexture");


    this->testShape = new TestShape(this->shader);
    this->objTest = new ObjLoader(this->shader, "test.obj");
    this->room = new RoomCube(this->shader);

    this->camera1 = new Camera(this->shader, 800, 600, 54.0f);
    this->camera2 = new Camera(this->shader, 800, 600, 54.0f);

    this->camera1->SetTranslation(0, 0, 2);
    this->camera2->SetTranslation(0, 0, 2);
    // this->camera->SetRotation(0,1,1,1);

    SDL_WarpMouseGlobal(500,500);// initialize mouse position
    // SDL_ShowCursor(0);
    this->cameraVelocity = glm::vec3(0.1f, 0.1f, 0.1f);    
    
    return true;
};

bool TestState :: Update(){

    // clear
    // SDL_GLContext cont = SDL_GL_GetCurrentContext();
    // setup your left view projection:
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glViewport(0,0,400, 600);
    // glOrtho(0, 800, 600, 0, -1, 1);
    // glMatrixMode(GL_MODELVIEW);
    // draw
    // setup your right view projection:
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glViewport(400,0,800, 600);
    // glOrtho(0, 800, 600, 0, -1, 1);
    // glMatrixMode(GL_MODELVIEW);
    // draw



    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // setup your left view projection:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,400, 600);
    glOrtho(0, 800, 600, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    // draw left view
    glUniform1i(this->hasTextureUniform, true);
    this-testShape->Draw();
    glUniform1i(this->hasTextureUniform, false);
    this->objTest->Draw();
    this->room->Draw();
    this->camera1->Update();

    // setup your right view projection:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(400,0,400, 600);
    glOrtho(0, 800, 600, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    
    // draw right view
    glUniform1i(this->hasTextureUniform, true);
    this-testShape->Draw();
    glUniform1i(this->hasTextureUniform, false);
    this->objTest->Draw();
    this->room->Draw();
    this->camera2->Update();

    const uint8_t* state = SDL_GetKeyboardState(NULL);

    // if(state[SDL_SCANCODE_RIGHT]){
    //     // change the state
    //     SetState<TestState2>(this->app);
    //     std :: cout << "Arrow Key Right" << std :: endl;
    // };

    /*
        cos(0)   =  1
        cos(90)  =  0
        cos(180) = -1
        cos(270) =  0
        -------------
        sin(0)   =  0
        sin(90)  =  1
        sin(180) =  0
        sin(270) = -1
    */

    /* - - - - - - Translations - - - - - - - - - - */
    if(state[SDL_SCANCODE_A]){
        // this->camera->Translate(0.1f, 0, 0);
        this->camera1->Translate(
            -this->cameraVelocity.x*cos(glm::radians(this->cameraRotation.y)), 
            0, 
            -this->cameraVelocity.z*sin(glm::radians(this->cameraRotation.y))
        );

        this->camera2->Translate(
            -this->cameraVelocity.x*cos(glm::radians(this->cameraRotation.y)), 
            0, 
            -this->cameraVelocity.z*sin(glm::radians(this->cameraRotation.y))
        );
        std :: cout << "Key A" << std :: endl;
    };
    if(state[SDL_SCANCODE_D]){
        // this->camera->Translate(-0.1f, 0, 0);
        this->camera1->Translate(
            this->cameraVelocity.x*cos(glm::radians(-this->cameraRotation.y)), 
            0, 
            this->cameraVelocity.z*sin(glm::radians(-this->cameraRotation.y))
        );
        this->camera2->Translate(
            this->cameraVelocity.x*cos(glm::radians(-this->cameraRotation.y)), 
            0, 
            this->cameraVelocity.z*sin(glm::radians(-this->cameraRotation.y))
        );
        std :: cout << "Key D" << std :: endl;
    };
    if(state[SDL_SCANCODE_W]){
        // this->camera->Translate(0, 0, -0.1f);
        this->camera1->Translate(
            -this->cameraVelocity.x*sin(glm::radians(this->cameraRotation.y)), 
            0, 
            -this->cameraVelocity.z*cos(glm::radians(this->cameraRotation.y))
        );
        this->camera2->Translate(
            -this->cameraVelocity.x*sin(glm::radians(this->cameraRotation.y)), 
            0, 
            -this->cameraVelocity.z*cos(glm::radians(this->cameraRotation.y))
        );
        std :: cout << "Key W" << std :: endl;
    };
    if(state[SDL_SCANCODE_S]){
        // this->camera->Translate(0, 0, 0.1f);
        this->camera1->Translate(
            this->cameraVelocity.x*sin(glm::radians(this->cameraRotation.y)), 
            0, 
            this->cameraVelocity.z*cos(glm::radians(this->cameraRotation.y))
        );
        this->camera2->Translate(
            this->cameraVelocity.x*sin(glm::radians(this->cameraRotation.y)), 
            0, 
            this->cameraVelocity.z*cos(glm::radians(this->cameraRotation.y))
        );
        std :: cout << "Key S" << std :: endl;
    };

    /* - - - - - - Rotations - - - - - - - - - - */

    if(state[SDL_SCANCODE_LEFT]){
        // this->camera->Rotate(1, 0, 1, 0);
        this->cameraRotation.y +=1;
        std :: cout << "Arrow Key Left" << std :: endl;
    };
    if(state[SDL_SCANCODE_RIGHT]){
        // this->camera->Rotate(-1, 0, 1, 0);
        this->cameraRotation.y -=1;
        std :: cout << "Arrow Key Right" << std :: endl;
    };
    if(state[SDL_SCANCODE_UP]){
        // this->camera->Rotate(1, 1, 0, 0);
        this->cameraRotation.x +=1;
        std :: cout << "Arrow Key Up" << std :: endl;
    };
    if(state[SDL_SCANCODE_DOWN]){
        // this->camera->Rotate(-1, 1, 0, 0);
        this->cameraRotation.x -=1;
        std :: cout << "Arrow Key Down" << std :: endl;
    };
    
    /* - - - - - - Mouse Interface - - - - - - - - - - */
    const float MOUSE_SPEED = 0.05f;
    int xPositionMouse;
    int yPositionMouse;    
    SDL_GetGlobalMouseState(&xPositionMouse, &yPositionMouse);
    SDL_WarpMouseGlobal(500,500);// initialize mouse position

    cameraRotation.y += MOUSE_SPEED * float(500 - xPositionMouse);
    cameraRotation.x += MOUSE_SPEED * float(500 - yPositionMouse);

    
    this->camera1->SetRotation(20,1,1,1);
    this->camera1->Rotate(cameraRotation.x, 1, 0, 0);
    this->camera1->Rotate(cameraRotation.y, 0, 1, 0);
    // this->camera->Rotate(cameraRotation.z, 0, 0, 1);

    this->camera2->SetRotation(10,1,1,1);
    this->camera2->Rotate(cameraRotation.x, 1, 0, 0);
    this->camera2->Rotate(cameraRotation.y, 0, 1, 0);
    // this->camera->Rotate(cameraRotation.z, 0, 0, 1);
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


GLfloat vData[] = { // vertex data
//    positions            colors              uv coordinates
    -0.5f,  0.5f,       1.0f, 0.0f, 0.0f,       0.0f, 0.0f, // top-left
     0.5f,  0.5f,       0.0f, 1.0f, 0.0f,       1.0f, 0.0f, // top-right
     0.5f, -0.5f,       0.0f, 0.0f, 1.0f,       1.0f, 1.0f, // bottom-right
    -0.5f, -0.5f,       1.0f, 1.0f, 1.0f,       0.0f, 1.0f  // bottom-left 
};

GLuint eData[] = { // element data
    0, 1, 2,
    2, 3, 0
};

TestShape :: TestShape(Shader* shader) : Drawable() {
    // glEnable(GL_TEXTURE_2D);

    this -> bindVAO();
    this -> loadVerticies(vData, 28);
    this -> loadElements(eData, 6);
    this -> posAtt = shader -> getAttribute("position");
    this -> colAtt = shader -> getAttribute("color");
    this -> uvAtt = shader-> getAttribute("uv");

    glEnableVertexAttribArray(this->posAtt);
    // define any of generic  vertex attribute data
    glVertexAttribPointer(
        this->posAtt, //GLuint index
        2, // GLint size
        GL_FLOAT, // GLenum type
        GL_FALSE, // GLboolean normalized
        7*sizeof(float), // GLstride 
        0 // const GLVoid* pointer
    );

    glEnableVertexAttribArray(this->colAtt);
    // define any of generic  vertex attribute data
    glVertexAttribPointer(
        this->colAtt, //GLuint index
        3, // GLint size
        GL_FLOAT, // GLenum type
        GL_FALSE, // GLboolean normalized
        7*sizeof(float), // GLstride 
        (void*)(2*sizeof(float)) // const GLVoid* pointer
    );

    glEnableVertexAttribArray(this->uvAtt);
    // define any of generic  vertex attribute data
    glVertexAttribPointer(
        this->uvAtt, //GLuint index
        2, // GLint size
        GL_FLOAT, // GLenum type
        GL_FALSE, // GLboolean normalized
        7*sizeof(float), // GLstride 
        (void*)(5*sizeof(float)) // const GLVoid* pointer
    );

    this->loadTexture("test.bmp");
};

TestShape :: ~TestShape(){};
