//
// Created by protoke on 06/02/17.
//

#ifndef AUPETITCRAFT_BLOCK_H
#define AUPETITCRAFT_BLOCK_H

#include <string>
#include <glm/vec3.hpp>
#include "../../graphicEngine/TextureManager.h"

class Block {
public:
    Block(int x, int y, int z);
    Block(glm::vec3 position);

    textureId getTextureId();
    glm::vec3 getPosition();

protected:
    glm::vec3 position_;
    textureId texId_;
};


#endif //AUPETITCRAFT_BLOCK_H
