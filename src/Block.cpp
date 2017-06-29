//
// Created by protoke on 06/02/17.
//

#include "Block.h"

Block::Block()
{}

Block::Block(BlockType type) :
        type_(type)
{}

bool Block::isActive() {
    return active_;
}

void Block::setActive(bool active) {
    active_ = active;
}

// OLD
//
//Block::Block(int x, int y, int z, const Chunk* chunk) :
//        chunk_(chunk),
//        position_(glm::vec3(x, y, z)),
//        texId_(STONE)
//{}
//
//Block::Block(glm::vec3 position, const Chunk* chunk) :
//        chunk_(chunk),
//        position_(position),
//        texId_(STONE)
//{}
//
//textureId Block::getTextureId() {
//    return texId_;
//}
//
//glm::vec3 Block::getPosition() {
//    return position_;
//}
