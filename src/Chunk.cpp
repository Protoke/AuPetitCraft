//
// Created by protoke on 06/02/17.
//

#include "Chunk.h"

Chunk::Chunk() {
    std::vector<Block*> vecZ(CHUNK_SIZE_Z, nullptr);
    std::vector<std::vector<Block*>> vecY(CHUNK_SIZE_Y, vecZ);
    blocks_ = std::vector<std::vector<std::vector<Block*>>>(CHUNK_SIZE_X, vecY);

    for (int x = 0; x < CHUNK_SIZE_X; ++x) {
        for (int y = 0; y < CHUNK_SIZE_Y; ++y) {
            for (int z = 0; z < CHUNK_SIZE_Z; ++z) {
                blocks_[x][y][z] = new Block(BlockType_Stone);
            }
        }
    }
}

Chunk::~Chunk() {
    for (int x = 0; x < CHUNK_SIZE_X; ++x) {
        for (int y = 0; y < CHUNK_SIZE_Y; ++y) {
            for (int z = 0; z < CHUNK_SIZE_Z; ++z) {
                delete blocks_[x][y][z];
            }
        }
    }
}

void Chunk::createMesh() {

}


// OLD
//
Block* Chunk::getBlock(int x, int y, int z) {
    return blocks_[x][y][z];
}