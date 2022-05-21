#include<Application.h>
#include<Shader.h>
#include<Drawable.h>


#ifndef TESTSHAPE_H
#define TESTSHAPE_H

class TestShape : public Drawable{
    private:
        GLint posAtt; //position attribute
        GLint colAtt; // color attribute 

    public:
        TestShape(Shader* shader);
        ~TestShape();
};

#endif

#ifndef TESTSTATE_H
#define TESTSTATE_H
class TestState : public GameState{
    private:
        Shader* shader;
        TestShape* testShape;
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

