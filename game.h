#ifndef GAME_HPP
#define GAME_HPP
#include <stdio.h>

class Game
{
private:
    bool isRunning;
    __event 

public:
    Game();
    ~Game();

    void handleEvents();
    void init();
    void update();
    void render();
    void clean();
    void start();

    bool run();
};

Game::Game(){

}

Game::~Game(){

}



#endif