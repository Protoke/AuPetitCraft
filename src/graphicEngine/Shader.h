//
// Created by protoke on 10/02/17.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// Include glew to get all the required OpenGL headers
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    GLuint program_;

    // Constructor generates the shader on the fly
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath) {
        // 1. Retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensures ifstream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::badbit);
        try {
            // Open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            // Read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // Convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure e) {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const GLchar *vShaderCode = vertexCode.c_str();
        const GLchar *fShaderCode = fragmentCode.c_str();
        // 2. Compile shaders
        GLuint vertex, fragment;
        GLint success;
        GLchar infoLog[512];
        // Vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        // Print compile errors if any
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // Fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        // Print compile errors if any
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // Shader Program
        this->program_ = glCreateProgram();
        glAttachShader(this->program_, vertex);
        glAttachShader(this->program_, fragment);
        glLinkProgram(this->program_);
        // Print linking errors if any
        glGetProgramiv(this->program_, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(this->program_, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        // Delete the shaders as they're linked into our program now and no longer necessery
        glDeleteShader(vertex);
        glDeleteShader(fragment);

    }

    // Uses the current shader
    void use() {
        glUseProgram(this->program_);
    }

    // TODO : ajouter la gestion d'un autre shader program d'utilisé, et faire en sorte que les setUniform modifient le bon programme
    // (sauvegarde du programme utilisé, et stockage temporaire pour en changer)

    void setUniform(const char *uniform, const GLuint v) {
        glUniform1ui(glGetUniformLocation(program_, uniform), v);
    }

    void setUniform(const char *uniform, const GLint v) {
        glUniform1i(glGetUniformLocation(program_, uniform), v);
    }

    void setUniform(const char *uniform, const GLfloat v) {
        glUniform1f(glGetUniformLocation(program_, uniform), v);
    }

    void setUniform(const char *uniform, const glm::vec2 &v) {
        glUniform2fv(glGetUniformLocation(program_, uniform), 1, glm::value_ptr(v));
    }

    void setUniform(const char *uniform, const glm::vec3 &v) {
        glUniform3fv(glGetUniformLocation(program_, uniform), 1, glm::value_ptr(v));
    }

    void setUniform(const char *uniform, const glm::vec4 &v) {
        glUniform4fv(glGetUniformLocation(program_, uniform), 1, glm::value_ptr(v));
    }

    void setUniform(const char *uniform, const glm::mat4 &v) {
        glUniformMatrix4fv(glGetUniformLocation(program_, uniform), 1, GL_FALSE, glm::value_ptr(v));
    }
};

#endif //SHADER_H
