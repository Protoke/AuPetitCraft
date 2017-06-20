//
// Created by protoke on 06/02/17.
//

#include "Game.h"
#include "../graphicEngine/GameRenderer.h"
#include "../Utilities/CustomException.h"


int main(){
    std::cout << "Starting" << std::endl;
    GameRenderer gm;

    return 0;
}

Game::Game(){

}

void Game::runGameLoop() {
    while(isRunning){
        throw new NotImplementedException();
    }
}

// Notes for later
// 1 minecraft tick = 10 redstone ticks
void Game::runTick() {
    throw new NotImplementedException();
}

void Game::runRedstoneTick() {
    throw new NotImplementedException();
}
