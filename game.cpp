#include "game.h"

Game::Game(){

}

Game::~Game(){

}

void Game::init(const char *title,int posx,int posy,int width,int height,bool fullscreen){
    int flags = 0;

    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Game is initialised" << std::endl;
        window = SDL_CreateWindow(title, posx, posy, width, height, flags);

        if(window){
            std::cout << "Window is created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer is created" << std::endl;
        }

        isRunning = true;
    }else
    {
        isRunning = false;
    }
    
}

void Game::update(){

}

void Game::start(){

}

void Game::render(){
    SDL_RenderClear(renderer);
    /*
    Add something to render
    */

   SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game cleanned" << std::endl;
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}