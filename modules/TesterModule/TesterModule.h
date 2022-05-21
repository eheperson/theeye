#include<Application.h>
#include<Shader.h>
#include<Drawable.h>
#include<Camera.h>
#include<RoomCube.h>

// #include<glm/glm.hpp>
// #include<glm/gtc/type_vec.hpp>
// #include<glm/gtx/rotate_vector.hpp>
// #include<glm/gtx/transform.hpp>
// #include<glm/gtc/type_ptr.hpp>



#ifndef TESTSHAPE_H
#define TESTSHAPE_H

class TestShape : public Drawable{
    private:
        GLint posAtt; //position attribute
        GLint colAtt; // color attribute 
        GLint uvAtt;

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
        RoomCube* room;
        Camera* camera;

        glm::vec3 cameraRotation;
        glm::vec3 cameraVelocity;

        GLint hasTextureUniform;

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

