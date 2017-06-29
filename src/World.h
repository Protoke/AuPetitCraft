//
// Created by protoke on 06/02/17.
//

#ifndef AUPETITCRAFT_WORLD_H
#define AUPETITCRAFT_WORLD_H

#include <glm/glm.hpp>
#include <unordered_map>
#include "Chunk.h"

typedef enum {
    OVERWORLD,
    NETHER,
    END
} worldId;

class World {
public:
    struct KeyHasher {
        std::size_t operator()(const glm::vec2 &v) const {
            return std::hash<int>()(v.x) ^ std::hash<int>()(v.y);
        }
    };

    typedef std::unordered_map<glm::vec2, Chunk*, KeyHasher> chunkMap;

    World();
    ~World();

    Chunk* getChunk(int x, int z);
    Chunk* getChunk(glm::vec2 pos);
    chunkMap getChunkMap();

private:
    chunkMap chunks_;
    worldId worldType_;

    Chunk* generateChunk(const int x, const int z);
    void deleteChunk(const int x, const int z);
};


#endif //AUPETITCRAFT_WORLD_H
