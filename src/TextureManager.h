//
// Created by protoke on 17/06/17.
//

#ifndef AUPETITCRAFT_TEXTUREMANAGER_H
#define AUPETITCRAFT_TEXTUREMANAGER_H

#include <unordered_map>
#include <GL/glew.h>
#include "Texture.h"

typedef enum {
    STONE,
    DIRT
} textureId;

class TextureManager {
    std::unordered_map<textureId, Texture, std::hash<int>> textures_;
    GLshort textureCount_ = 0;

public:
    int loadTexture(const std::string &path, const textureId id);
    Texture getTexture(const textureId id);
};


#endif //AUPETITCRAFT_TEXTUREMANAGER_H
