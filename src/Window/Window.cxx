#include "Window.h"

Window :: Window(const std :: string& title, int width, int height){
    // Before we create our window, specify OpenGL version
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    // set glad profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    // 
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    // SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    // SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    // SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    // SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    this->sdlWindow = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, 
        height, 
        SDL_WINDOW_FLAGS
    );
    if(this->sdlWindow == nullptr){
        throw WindowException(SDL_GetError());
    }else{
        this->InitGLContext();
    };
};

Window :: Window(const std :: string& title, int x, int y, int width, int height){
    this->sdlWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_FLAGS);
    if(this->sdlWindow == nullptr){
        throw WindowException(SDL_GetError());
    }else{
        this->InitGLContext();
    }
};

Window :: ~Window(){
    SDL_GL_DeleteContext(this->sdlGLContext);
    SDL_DestroyWindow(this->sdlWindow);
};

void Window :: InitGLContext(){
    this->sdlGLContext = SDL_GL_CreateContext(this->sdlWindow);
    
    // Setup our function pointers
    // gladLoadGLLoader(SDL_GL_GetProcAddress);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    // // Check OpenGL properties
    #ifndef NDEBUG // or _DEBUG
        std :: cout << "---------------------------" << std::endl;
        std :: cout << "     - OpenGL loaded -     " << std::endl;
        // gladLoadGLLoader(SDL_GL_GetProcAddress);
        std :: cout << "Vendor:   " <<  glGetString(GL_VENDOR) << std::endl;
        std :: cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
        std :: cout << "Version:  " << glGetString(GL_VERSION) << std::endl;
        std :: cout << "---------------------------" << std::endl;
    #endif // NDEBUG

    if(this->sdlGLContext == nullptr){
        throw GLContextException(SDL_GetError());
    }else{
        if(SDL_GL_SetSwapInterval(1) < 0){
            throw GLContextException(SDL_GetError());
        }
    };
};

void Window :: Update(){
    SDL_GL_SwapWindow(this->sdlWindow);
};