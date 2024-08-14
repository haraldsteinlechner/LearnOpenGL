#include <learnopengl/camera.h>


const float ROTATIONSENSITIVITY = 0.01f;
const float ZOOMSENSITIVITY = 0.1;

class OrbitCamera
{
private:
    float Pitch;
    float Yaw;
    float Radius;
    float RotateSensitivity;
    float ZoomSensitivity;
    bool MouseDown = false;

public:
	OrbitCamera(float radius) : Radius(radius), RotateSensitivity(ROTATIONSENSITIVITY), ZoomSensitivity(ZOOMSENSITIVITY), MouseDown(false) {
        Pitch = 0.0f;
        Yaw = 0.0f;
	}

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix()
    {
        glm::mat4 m = glm::mat4(1.0);
        m = glm::translate(m, glm::vec3(0.0, 0.0, -Radius));
        m = glm::rotate(m, Yaw, glm::vec3(0.0, 1.0, 0.0));
        m = glm::rotate(m, Pitch, glm::vec3(1.0, 0.0, 0.0));
        return m;
    }

    void ProcessMouseOrbit(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        if (MouseDown) {


            xoffset *= RotateSensitivity;
            yoffset *= RotateSensitivity;

            Yaw += xoffset;
            Pitch -= yoffset;

            // make sure that when pitch is out of bounds, screen doesn't get flipped
            if (constrainPitch)
            {
                if (Pitch > 89.0f)
                    Pitch = 89.0f;
                if (Pitch < -89.0f)
                    Pitch = -89.0f;
            }
        }
    }

    void ProcessMouseOrbitScroll(float yoffset) {
        Radius -= yoffset * ZoomSensitivity;
    }

    void ProcessMouseDown(bool down) {
        MouseDown = down;
    }
};