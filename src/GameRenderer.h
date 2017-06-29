//
// Created by protoke on 25/02/17.
//

#ifndef AUPETITCRAFT_GAMEENGINE_H
#define AUPETITCRAFT_GAMEENGINE_H

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Others
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// headers
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"
#include "TextureManager.h"


class GameRenderer {
public:
    GameRenderer();
    void static key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    void static mouse_callback(GLFWwindow* window, double xpos, double ypos);
    int initApp(GLFWwindow*& window, int width, int height);
    void do_movement();
    void static scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    const GLuint WIDTH = 1024, HEIGHT = 720;
    bool keys[1024];
    GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
    GLfloat lastFrame = 0.0f;  	// Time of last frame

    // Camera
    Camera camera;
    GLfloat lastX =  WIDTH  / 2.0;
    GLfloat lastY =  HEIGHT / 2.0;
    bool firstMouse = true;
};


#endif //AUPETITCRAFT_GAMEENGINE_H
