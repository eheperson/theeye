#include "Window.h"

Window :: Window(const std :: string& title, int width, int height){
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
    }
    else{
        this->InitRenderer();
    };
};

Window :: Window(const std :: string& title, int x, int y, int width, int height){
    this->sdlWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_FLAGS);
    if(this->sdlWindow == nullptr){
        throw WindowException(SDL_GetError());
    }
    else{
        this->InitRenderer();
    }
};

Window :: ~Window(){
    SDL_DestroyWindow(this->sdlWindow);
};

void Window :: InitRenderer(){
    this->sdlRenderer = SDL_CreateRenderer(
        this->sdlWindow,
        -1,
        SDL_RENDERER_FLAGS
    );
    if(this->sdlRenderer == nullptr){
        throw RendererException(SDL_GetError());
    };
};

