#include "Game.h"

Game::Game(){
  init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,false);
  ball = new Ball();
  xBorder = (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 10);
  yBorder = (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 10);
  //player1 = new Player(1);
  //player2 = new Player(2);
  players[0] = new Player(1);
  players[1] = new Player(2);
}

int Game::execute(){
  while(isRunning){
    handleEvents();
    loop();
    render();
  }
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool full){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
    isRunning = false;
    return;
  }

  int flags = 0;
  if(full){
    flags = SDL_WINDOW_FULLSCREEN;
  }
  
  window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
  if(!window){
    isRunning = false;
    return;
  }
  
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(!renderer){
    isRunning = false;
    return;
  }
  SDL_SetRenderDrawColor(renderer,255,255,255,255);
  
  isRunning = true;
  
}

void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);

  switch(event.type){
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

void Game::loop(){
  ball->bounce(players);
}

void Game::render(){
  SDL_RenderClear(renderer);


  SDL_RenderPresent(renderer);
}

void Game::cleanUp(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
