//
// Created by protoke on 06/02/17.
//

#include "World.h"

World::World() :
        worldType_(OVERWORLD)
{
    for (int x = -1; x <= 1; ++x) {
        for (int z = -1; z <= 1; ++z) {
            generateChunk(x, z);
        }
    }
}

World::~World() {
    for(chunkMap::iterator itr = chunks_.begin(); itr != chunks_.end(); itr++) {
        delete itr->second;
        chunks_.erase(itr);
    }
}

Chunk* World::getChunk(int x, int z) {
    return getChunk(glm::vec2(x, z));
}

Chunk* World::getChunk(glm::vec2 pos) {
    return chunks_[pos];
}

World::chunkMap World::getChunkMap() {
    return chunks_;
}

Chunk* World::generateChunk(const int x, const int z) {
    glm::vec2 pos(x, z);

    if(chunks_.count(pos) > 0)
        return chunks_[pos];

    Chunk* chunk = new Chunk();
    chunks_[pos] = chunk;
    return chunk;
}

void World::deleteChunk(const int x, const int z) {
    glm::vec2 pos(x, z);

    delete chunks_[pos];
    chunks_.erase(pos);
}