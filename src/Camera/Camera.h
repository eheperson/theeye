#include<Shader.h>

#ifndef CAMERA_H
#define CAMERA_H

class Camera{

    private:

        glm::mat4 projectMatrix;
        glm::mat4 viewMatrix;

        glm::mat4 translation;
        glm::mat4 rotation;

        Shader* shader;

        int vpUniform;

        void UpdateViewMatrix();

    public:

        Camera(Shader* shader, float w, float h, float degree);

        void SetShader(Shader* shader);

        void SetTranslation(float x, float y, float z);
        void SetRotation(float rotation, float x, float y, float z);

        void Translate(float x, float y, float z);
        void Rotate(float rotation, float x, float y, float z);

        void Update();


};

#endif