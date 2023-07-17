#pragma once
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include "glm/glm.hpp"

// Default camera values
const float YAW          = -90.0f;
const float PITCH        =  0.0f;
const float PERSPECTIVE  =  60.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    glm::vec3 Position, Front, Up, Right, WorldUp;
    // euler Angles
    float Yaw, Pitch;
    // camera options
    float MovementSpeed, MouseSensitivity, Perspective;

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
        float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)),  Perspective(PERSPECTIVE)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors()
    {
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

        Front = glm::normalize(front);
        Position = -Front * sqrt(dot(Position, Position));

        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = glm::normalize(glm::cross(Right, Front));
    }

    void SetProjectionMatrix(int Width, int Height) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(Perspective, (GLfloat)Width / Height, 0.15, 1000.0);
        glm::vec3 dest = Position + Front;
        gluLookAt(Position.x, Position.y, Position.z, dest.x, dest.y, dest.z, Up.x, Up.y, Up.z);
        glMatrixMode(GL_MODELVIEW);
    }

    void Update(float yaw, float pitch, float distance, int Width, int Height) {
        Yaw = -yaw - 90;
        Pitch = -pitch;
        Position = normalize(Position) * distance;
        updateCameraVectors();
        SetProjectionMatrix(Width, Height);
    }
};
