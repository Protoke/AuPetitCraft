//
// Created by protoke on 06/02/17.
//

#ifndef AUPETITCRAFT_GAME_H
#define AUPETITCRAFT_GAME_H


#include "../graphicEngine/TextureManager.h"

class Game {
public:
    Game();
    void runGameLoop();
    void runTick();
    void runRedstoneTick();


private:
    bool isRunning;
};


#endif //AUPETITCRAFT_GAME_H
