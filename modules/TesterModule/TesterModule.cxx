#include "TesterModule.h"

TestState :: TestState(Application* app) : GameState(app) {};

bool TestState :: Init(){
    glClearColor(1,0,0,1);
    return true;
};

bool TestState :: Update(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

TestState2 :: ~TestState2(){
    
};