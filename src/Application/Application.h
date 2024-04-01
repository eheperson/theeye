#include<Window.h>
#include<glad/glad.h>

#define SDL_INIT_FLAGS SDL_INIT_VIDEO

#ifndef GAMESTATEBASE_H
#define GAMESTATEBASE_H
class GameStateBase{
    public:
        virtual bool Init() = 0;
        virtual bool Update() = 0;
        virtual bool Destroy() = 0 ;

};
#endif //GAMESTATEBASE

#ifndef APPLICATION_H
#define APPLICATION_H


class ApplicationException : public std::runtime_error{
    public:
        ApplicationException(const std :: string& error) : std :: runtime_error(error){
            
        };
};

class Application{
    public:
        // static Application* Instance();
        Application();
        bool Run();
        void Stop();
        void SetState(GameStateBase* state);
        ~Application();
    private:
        bool active;
        Window* window;
        GameStateBase* state = nullptr;
};

template<class T>
void SetState(Application* app){
    app->SetState(new T(app));
};


#endif

#ifndef GAMESTATE_H
#define GAMESTATE_H
class GameState : public GameStateBase{
    public:
        GameState(Application* app){
            this->app = app;
        };
    protected:
        Application* app;
};
#endif //GAMESTATE
