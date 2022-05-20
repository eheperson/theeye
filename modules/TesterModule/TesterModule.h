#include<Application.h>
#include<Shader.h>

#include<SDL2/SDL.h>
#include<glad/glad.h>

#ifndef TESTSTATE_H
#define TESTSTATE_H
class TestState : public GameState{
    private:
        // pass
    public:
        TestState(Application* app);
        bool Init();
        bool Update();
        bool Destroy();
        ~TestState();

};
#endif //TESTSTATE


#ifndef TESTSTATE2_H
#define TESTSTATE2_H
class TestState2 : public GameState{
    private:

    public:
        TestState2(Application* app);
        bool Init();
        bool Update();
        bool Destroy();
        ~TestState2();

};
#endif //TESTSTATE2