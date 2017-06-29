//
// Created by protoke on 06/02/17.
//

#ifndef AUPETITCRAFT_GAME_H
#define AUPETITCRAFT_GAME_H


#include "../TextureManager.h"
#include "RenderEngine.h"


class Launcher {
public:
    Launcher() {}

    RenderEngine renderengine_;


private:
    bool isRunning;
};


#endif //AUPETITCRAFT_GAME_H
