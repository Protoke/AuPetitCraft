//
// Created by protoke on 25/02/17.
//

#ifndef AUPETITCRAFT_BLOCKRENDER_H
#define AUPETITCRAFT_BLOCKRENDER_H

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/detail/type_mat.hpp>

#include "Shader.h"
#include "TextureManager.h"
#include "Block.h"

// TODO : Make singleton
class BlockRender {
public:
    BlockRender(TextureManager &tm);

    void startDrawing();
    void stopDrawing();
    void draw(glm::vec3 pos, Shader shaderProgram);

private:
    TextureManager textureManager_;

    bool drawing_ = false;

    GLuint VAO_;
    GLfloat vertices_[180] = {
            // Positions         // Texture Coords
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
};


#endif //AUPETITCRAFT_BLOCKRENDER_H
