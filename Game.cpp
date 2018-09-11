#include "Game.h"

Game::Game(){
  init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,false);
  ball = new Ball();
  scoreBoard[0] = 0;
  scoreBoard[1] = 1;
  xBorder = (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 10);
  yBorder = (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 10);
  player1 = new Player(1);
  player2 = new Player(2);
  //players[0] = new Player(1);
  //players[1] = new Player(2);
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
  SDL_SetRenderDrawColor(renderer,0,0,0,0);
  
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
  /*static int tick = 0;
  if(tick++ == 20){
    ball->move();
    players[0]->move();
    players[1]->move();
    tick = 0;
    checkBounce();
    }*/
  
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

void Game::checkBounce(){
  
  ///// Ball hits a paddle
  ///// Left
  if(ball->getXVel() < 0){
    if((*(ball->getPos()) - ball->getHalfWidth()) < (player1->getPaddle()->getXPos() + player1->getPaddle()->getHalfWidth())){
      if(((*(ball->getPos()+ 1) + ball->getHalfWidth()) > (player1->getPaddle()->getYPos() - player1->getPaddle()->getHalfHeight()))
	 && ((*(ball->getPos()+ 1) - ball->getHalfWidth()) < (player1->getPaddle()->getYPos() + player1->getPaddle()->getHalfHeight()))){
	ball->bounce(0);
      }
    }
    ///// Right
  }else{
    if((*(ball->getPos()) + ball->getHalfWidth()) > (player1->getPaddle()->getXPos() - player1->getPaddle()->getHalfWidth())){
      if(((*(ball->getPos()+ 1) + ball->getHalfWidth()) > (player1->getPaddle()->getYPos() - player1->getPaddle()->getHalfHeight()))
	 && ((*(ball->getPos()+ 1) - ball->getHalfWidth()) < (player1->getPaddle()->getYPos() + player1->getPaddle()->getHalfHeight()))){
	ball->bounce(0);
      }
    }
  }
  ///// Ball hits the bottom or top wall
  ///// Top
  if(ball->getYVel() > 0){
    if(*(ball->getPos() + 1) + ball->getHalfWidth() > YBORDER){
      ball->bounce(1);
    }
    ///// Bot
  }else{
    if(*(ball->getPos() + 1) + ball->getHalfWidth() > -YBORDER){
      ball->bounce(1);
    }
  }
  
}

void Game::checkIfScore(){
  
  ///// Ball hits either side of XBORDER
  /////Score against Left, point to right (player 2)
  if(ball->getXVel() < 0){
    if(*(ball->getPos()) - ball->getHalfWidth() < -XBORDER){
      player2->incScore();
      scoreBoard[1]++;
    }
    ///// Score against right, point to left (player 1)
  }else{
    if(*(ball->getPos()) + ball->getHalfWidth() > XBORDER){
      player1->incScore();
      scoreBoard[0]++;
    }
  }
}
