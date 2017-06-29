//
// Created by protoke on 06/02/17.
//

#ifndef AUPETITCRAFT_CHUNK_H
#define AUPETITCRAFT_CHUNK_H

#include <vector>
#include "Block.h"

class Chunk {
public:
    static const unsigned int CHUNK_SIZE_X = 16;
    static const unsigned int CHUNK_SIZE_Y = 16;
    static const unsigned int CHUNK_SIZE_Z = 16;

    Chunk();
    ~Chunk();

    void update(float dt);
    void render();

    void createMesh();

    Block* getBlock(int x, int y, int z);

private:
    std::vector<std::vector<std::vector<Block*>>> blocks_;
};


#endif //AUPETITCRAFT_CHUNK_H
