//
// Created by protoke on 17/06/17.
//

#include "Stone.h"

Stone::Stone(int x, int y, int z) :
        Block(x, y, z)
{
    texId_ = STONE;
}

Stone::Stone(glm::vec3 position) :
        Block(position)
{
    texId_ = STONE;
}