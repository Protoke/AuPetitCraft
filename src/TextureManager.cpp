//
// Created by protoke on 17/06/17.
//

#include <iostream>
#include <cstring>
#include "TextureManager.h"


int TextureManager::loadTexture(const std::string &path, const textureId id){
    if(textures_.count(id))
        return 1;


    /***** Agrandissement de la texture *****/
    int width, height, scale = 32;
    unsigned char* image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
    int widthStep = width * SOIL_LOAD_RGBA * sizeof(unsigned char);
    int nWidth = width * scale;
    int nHeight = height * scale;
    unsigned char* largerImage = new unsigned char[sizeof(unsigned char) * nWidth * nHeight * SOIL_LOAD_RGBA];
    int nWidthStep = nWidth * SOIL_LOAD_RGBA * sizeof(unsigned char);

    for(int i=0; i < nHeight; i++)
        if(i%scale==0)
            for(int j=0; j < nWidth; j++)
                if(j%scale==0)
                    for(int k=0; k < SOIL_LOAD_RGBA; k++)
                        for(int px=0; px < scale; px++)
                            for(int py=0; py < scale; py++)
                                largerImage[(i+px)*nWidthStep+(j+py)*SOIL_LOAD_RGBA+k] = image[(i*widthStep)/scale+(j*SOIL_LOAD_RGBA)/scale+k];

    SOIL_save_image("/home/protoke/Documents/Projet Minecraft/tests/stone.bmp", SOIL_SAVE_TYPE_BMP, nWidth, nHeight, SOIL_LOAD_RGBA, largerImage);

    Texture texture(largerImage, width*scale, height*scale, textureCount_);
    //Texture texture(path, textureCount_);
    textures_[id] = texture;
    textureCount_++;

    SOIL_free_image_data(image);
    delete(largerImage);

    return 0;
}

Texture TextureManager::getTexture(const textureId id){
    if(!textures_.count(id)) {
        /*throw new std::logic_error("Texture not loaded.");*/
        std::cerr << "Texture not found" << std::endl;
        return Texture();
    }

    return textures_[id];
}