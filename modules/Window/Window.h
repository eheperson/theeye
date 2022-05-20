#include <cstdio>
#include <cstdlib>

#include<iostream>
#include<string>
#include<exception>
#include<theeyeConfig.h>
#include<SDL2/SDL.h>
#include<glad/glad.h>

#ifndef WINDOW_H
#define WINDOW_H

#define SDL_WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
#define SDL_RENDERER_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

class WindowException : public std::runtime_error{
    public:
        WindowException(const std :: string& error) : std :: runtime_error(error){};
};

class GLContextException : public std::runtime_error{
    public:
        GLContextException(const std :: string& error) : std :: runtime_error(error){};
};

class Window{
    private:
        SDL_Window* sdlWindow;
        SDL_GLContext sdlGLContext;
        void InitGLContext();
    public:
        Window(
            // centered window
            const std::string& title, 
            int width, 
            int height
        );
        Window(
            // position specific window
            const std::string& title, 
            int x, 
            int y,
            int width,
            int height
        );
        ~Window();
        void Update();
};


#endif // WINDOW_H