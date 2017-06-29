//
// Created by protoke on 21/06/17.
//

#ifndef AUPETITCRAFT_WORLDRENDERER_H
#define AUPETITCRAFT_WORLDRENDERER_H


#include "World.h"
#include "BlockRender.h"

class WorldRender {
public:
    WorldRender(World *world, BlockRender br);

    void drawWorld(Shader shaderProgram);

private:
    World* world_;

    BlockRender br_;

    void drawChunk(Chunk* chunk, Shader shaderProgram);
};


#endif //AUPETITCRAFT_WORLDRENDERER_H
