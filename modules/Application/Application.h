#include<Window.h>

#ifndef APPLICATION_H
#define APPLICATION_H

#define SDL_INIT_FLAGS SDL_INIT_VIDEO

class ApplicationException : public std::runtime_error{
    public:
        ApplicationException(const std :: string& error) : std :: runtime_error(error){
            
        };
};

class Application{
    private:
        Application();
        ~Application();
        static Application* applicationInstance; // Single instance principle
        bool active;
        Window* window;
    public:
        static Application* Instance();
        bool Run();
        void Stop();

};

#endif
