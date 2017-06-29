//
// Created by protoke on 06/02/17.
//

#ifndef AUPETITCRAFT_BLOCK_H
#define AUPETITCRAFT_BLOCK_H

enum BlockType{
    BlockType_Stone,
    BlockType_Grass
};

class Block {
public:
    Block();
    Block(BlockType type);

    bool isActive();
    void setActive(bool active);

protected:
    BlockType type_;
    bool active_;
};


#endif //AUPETITCRAFT_BLOCK_H
