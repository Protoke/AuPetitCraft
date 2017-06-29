//
// Created by protoke on 12/02/17.
//

#include <SOIL.h>

#ifndef TESTOPENGL_TEXTURE_H
#define TESTOPENGL_TEXTURE_H


class Texture {
    GLuint texture;
    GLshort location;

public:
    Texture(){
        texture = 0;
        location = -1;
    }

    Texture(std::string path, GLshort unitTexture)
    {
        int width, height;

        this->location = unitTexture;

        glGenTextures(1, &(this->texture));

        glActiveTexture(GL_TEXTURE0 + this->location);
        glBindTexture(GL_TEXTURE_2D, this->texture);

        unsigned char* image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);

        SOIL_free_image_data(image);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture(unsigned char* image, int width, int height, GLshort unitTexture)
    {
        this->location = unitTexture;

        glGenTextures(1, &(this->texture));

        glActiveTexture(GL_TEXTURE0 + this->location);
        glBindTexture(GL_TEXTURE_2D, this->texture);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void use()
    {
        glActiveTexture(GL_TEXTURE0 + this->location);
        glBindTexture(GL_TEXTURE_2D, this->texture);
    }

    static void configTextures()
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    }

    GLshort getLocation(){
        return location;
    }
};


#endif //TESTOPENGL_TEXTURE_H
