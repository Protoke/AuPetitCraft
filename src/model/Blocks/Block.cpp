//
// Created by protoke on 06/02/17.
//

#include "Block.h"

Block::Block(int x, int y, int z) :
        position_(glm::vec3(x, y, z))
{}

Block::Block(glm::vec3 position) :
        position_(position)
{}

textureId Block::getTextureId() {
    return texId_;
}

glm::vec3 Block::getPosition() {
    return position_;
}
