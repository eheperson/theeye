#include "Application.h"

// initializing static object
Application* Application :: applicationInstance = nullptr;

Application* Application :: Instance(){
  if(applicationInstance == nullptr){
    Application::applicationInstance = new Application();
  };
  return Application :: applicationInstance;
}

Application :: Application(){
    this->active = true;
    try{
      if(SDL_Init(SDL_INIT_FLAGS) != 0){
        throw ApplicationException(SDL_GetError());
      }else{
        this->window = new Window("Test Window", 640, 480);
      };
    }catch(ApplicationException& exception){
      std :: cout << "Application Error : ";
      #ifndef NDEBUG
        std :: cout << "Line 16 in Application.cpp: "; // SDL_Init()
      #endif // NDEBUG
      std :: cout << exception.what() << std :: endl;
    }catch(WindowException& exception){
      std :: cout << "Window Error : ";
      #ifndef NDEBUG // or _DEBUG
        std :: cout << "Line 4 in Window.cpp: "; //vSDL_CreateWindow()
      #endif // NDEBUG
      std :: cout << exception.what() << std :: endl;
    }catch(GLContextException& exception){
      std :: cout << "GL Context Error : ";
      #ifndef NDEBUG // or _DEBUG
        std :: cout << "Line 33 in Window.cpp: "; // SDL_GL_CreateContext()
      #endif // NDEBUG
      std :: cout << exception.what() << std :: endl;
    };
}

bool Application :: Run(){
  if(this -> active){
    SDL_Event event;
      while(SDL_PollEvent(&event)){
        switch(event.type){
          case SDL_QUIT:
            this -> Stop();
            break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
              case SDLK_ESCAPE:
                this-> Stop();
                break;
            };
        };
      };
    // glClearColor(0,0,0,1);
    // glClear(GL_COLOR_BUFFER_BIT);
    this->window->Update();
  };
  return this->active;
};

void Application :: Stop(){
  this -> active = false;
}

Application :: ~Application(){
  SDL_Quit();
}