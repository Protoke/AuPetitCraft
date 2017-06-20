//
// Created by protoke on 17/06/17.
//

#ifndef AUPETITCRAFT_STONE_H
#define AUPETITCRAFT_STONE_H


#include "Block.h"

class Stone : public Block {

public:
    Stone(int x, int y, int z);
    Stone(glm::vec3 position);
};


#endif //AUPETITCRAFT_STONE_H
