//
// Created by protoke on 21/06/17.
//

#include "WorldRender.h"

WorldRender::WorldRender(World *world, BlockRender br) :
        world_(world),
        br_(br)
{}

void WorldRender::drawWorld(Shader shaderProgram) {
    World::chunkMap chunks = world_->getChunkMap();
    for(World::chunkMap::iterator itr = chunks.begin(); itr != chunks.end(); ++itr){
        drawChunk(itr->second, shaderProgram);
    }
}

void WorldRender::drawChunk(Chunk *chunk, Shader shaderProgram) {
    for (int x = 0; x < Chunk::CHUNK_SIZE_X; ++x) {
        for (int y = 0; y < Chunk::CHUNK_SIZE_Y; ++y) {
            for (int z = 0; z < Chunk::CHUNK_SIZE_Z; ++z) {
                Block *block = chunk->getBlock(x, y, z);
                if(block != NULL)
                    br_.draw(glm::vec3(x, y, z), shaderProgram);
            }
        }
    }
}