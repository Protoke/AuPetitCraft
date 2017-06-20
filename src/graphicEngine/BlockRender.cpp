//
// Created by protoke on 25/02/17.
//

#include <glm/gtc/matrix_transform.hpp>
#include "BlockRender.h"

BlockRender::BlockRender(TextureManager &tm) :
        textureManager_(tm)
{
    GLuint VBO;
    // Génération du buffer stockant les vertices
    glGenBuffers(1, &VBO);
    // Création du vertex array
    glGenVertexArrays(1, &VAO_);

    // Set du VAO (qui sauvegarde un "profil" d'affichage)
    // 1. Bind Vertex Array Object
    glBindVertexArray(VAO_);
        // 2. Copy our vertices array in a buffer for OpenGL to use
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_, GL_STATIC_DRAW);
        // 3. Then set our vertex attributes pointers
        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        // Texture attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
    //4. Unbind the VAO
    glBindVertexArray(0);
}

void BlockRender::startDrawing() {
    glBindVertexArray(VAO_);
    drawing_ = true;
}

void BlockRender::stopDrawing() {
    glBindVertexArray(0);
    drawing_ = false;
}

void BlockRender::draw(Block b, Shader shaderProgram) {
    if(drawing_ == false)
        glBindVertexArray(VAO_);

    // Texture
    Texture tex = textureManager_.getTexture(b.getTextureId());
    tex.use();
    glUniform1i(glGetUniformLocation(shaderProgram.program_, "ourTexture1"), tex.getLocation());

    // Model matrix
    glm::mat4 model;
    model = glm::translate(model, b.getPosition());
    shaderProgram.setUniform("model", model);

    // Drawing
    glDrawArrays(GL_TRIANGLES, 0, 36);

    if(drawing_ == false)
        glBindVertexArray(0);
}