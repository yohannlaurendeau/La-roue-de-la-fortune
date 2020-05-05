#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include "SDL2/SDL.h"

class Game
{
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Game();
    ~Game();

    void handleEvents();
    void init(const char *title,int posx,int posy,int width,int height,bool fullscreen);
    void update();
    void render();
    void clean();
    void start();

    bool run(){return isRunning;}
};

Game::Game(){

}

Game::~Game(){

}



#endif