//
// Created by protoke on 06/02/17.
//

#ifndef AUPETITCRAFT_MINECRAFT_H
#define AUPETITCRAFT_MINECRAFT_H


class Minecraft {
    void runGameLoop();
    void runTick();
    void runRedstoneTick();

private:
    bool isRunning;
};


#endif //AUPETITCRAFT_MINECRAFT_H
