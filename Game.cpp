#include "Game.h"

Game::Game(){
  //init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,false);
  //ball = new Ball();
  scoreBoard[0] = 0;
  scoreBoard[1] = 1;
  xBorder = (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 10);
  yBorder = (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 10);
  ball = new Ball();
  player1 = new Player(1);
  player2 = new Player(2);
  //players[0] = new Player(1);
  //players[1] = new Player(2);
  init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,false);
  

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
  //IMG_Init(IMG_INIT_JPG);
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

  //image = IMG_Load("rect.jpg");
  //texture= SDL_CreateTextureFromSurface(renderer, image);
  
  isRunning = true;
  
}

void Game::handleEvents(){
  SDL_Event event;
  //SDL_PollEvent(&event);
  SDL_PumpEvents();

  const Uint8 *keystate = SDL_GetKeyboardState(NULL);
  if(keystate[SDL_SCANCODE_UP]){
      player2->setNextLoc(1);
    }else if(keystate[SDL_SCANCODE_DOWN]){
      player2->setNextLoc(-1);
    }else if(keystate[SDL_SCANCODE_W]){
      player1->setNextLoc(1);
    }else if(keystate[SDL_SCANCODE_S]){
      player1->setNextLoc(-1);
  }else if(keystate[SDL_SCANCODE_G]){
    isRunning = false;
  }

  /*SDL_PollEvent(&event);


  switch(event.type){
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_KEYDOWN:
    //SDLKey keyPressed = SDL_GetKeyName(event.key.keysym.sym);
    if(keystate[SDL_SCANCODE_UP]){
      player2->setNextLoc(1);
    }else if(keystate[SDL_SCANCODE_DOWN]){
      player2->setNextLoc(-1);
    }else if(keystate[SDL_SCANCODE_W]){
      player1->setNextLoc(1);
    }else if(keystate[SDL_SCANCODE_S]){
      player1->setNextLoc(-1);
    }
    break;
  case SDL_MOUSEBUTTONDOWN:
    isRunning = false;
    break;
  default:
    break;
  }
  

  */

  /*
  switch(event.type){
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_KEYDOWN:
    //SDLKey keyPressed = SDL_GetKeyName(event.key.keysym.sym);
    if(event.key.keysym.sym == SDLK_UP){
      player2->setNextLoc(1);
    }else if(event.key.keysym.sym == SDLK_DOWN){
      player2->setNextLoc(-1);
    }else if(event.key.keysym.sym == SDLK_w){
      player1->setNextLoc(1);
    }else if(event.key.keysym.sym == SDLK_s){
      player1->setNextLoc(-1);
    }else{
      isRunning = false;
    }
    break;
  case SDL_MOUSEBUTTONDOWN:
    isRunning = false;
    break;
  default:
    break;
  }*/
}

void Game::loop(){
  static int tick = 0;
  if(tick++ == 10){
    ball->move();
    player1->move();
    player2->move();
    tick = 0;
    checkIfScore();
    checkBounce();
    }
  
}

void Game::render(){
  //SDL_SetRenderDrawColor(renderer,0,0,0,0);
  //SDL_RenderClear(renderer);
  static int tick = 0;
  if(tick++ == 10){
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
    ball->draw(renderer);
    player1->drawPaddle(renderer);
    player2->drawPaddle(renderer);
    tick = 0;
  }
  //SDL_RenderCopy(renderer,texture, NULL, NULL);
  //SDL_SetRenderDrawColor(renderer, 255,255,255,255);
  //for(int i = 0; i < 100; i++){
  //SDL_RenderDrawPoint(renderer,400 + i,300);
    //SDL_RenderPresent(renderer);
  //}
  SDL_RenderPresent(renderer);
  //SDL_RenderFillRect(renderer, &rect);
}

void Game::cleanUp(){
  ball->~Ball();
  player1->~Player();
  player2->~Player();
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::checkBounce(){
  
  ///// Ball hits a paddle
  ///// Left
  if(ball->getXVel() < 0){
    int ballX = *ball->getPos();
    int ballY = *(ball->getPos() + 1);
    int paddleX = player1->getPaddle()->getXPos();
    int paddleY = player1->getPaddle()->getYPos();
    if((ballX - ball->getHalfWidth()) < (paddleX + player1->getPaddle()->getHalfWidth())){
      if((ballY + ball->getHalfWidth()) > (paddleY - player1->getPaddle()->getHalfHeight())
	 && ((ballY - ball->getHalfWidth()) < (paddleY + player1->getPaddle()->getHalfHeight()))){
	ball->bounce(0);
      }
    }
    ///// Right
  }else{
    int ballX = *ball->getPos();
    int ballY = *(ball->getPos() + 1);
    int paddleX = player2->getPaddle()->getXPos();
    int paddleY = player2->getPaddle()->getYPos();
    if((ballX - ball->getHalfWidth()) < (paddleX + player2->getPaddle()->getHalfWidth())){
      if((ballY + ball->getHalfWidth()) > (paddleY - player2->getPaddle()->getHalfHeight())
	 && ((ballY - ball->getHalfWidth()) < (paddleY + player2->getPaddle()->getHalfHeight()))){
	ball->bounce(0);
      }
    }
  }
  ///// Ball hits the bottom or top wall
  ///// Top
  if(ball->getYVel() < 0){
    if(*(ball->getPos() + 1) - ball->getHalfWidth() < YBORDER){
      ball->bounce(1);
    }
    ///// Bot
  }else{
    if(*(ball->getPos() + 1) + ball->getHalfWidth() > SCREEN_HEIGHT - YBORDER){
      ball->bounce(1);
    }
  }
  
}

void Game::checkIfScore(){
  
  ///// Ball hits either side of XBORDER
  /////Score against Left, point to right (player 2)
  //ball->reset(2);
  if(ball->getXVel() < 0){
    if(*(ball->getPos()) - ball->getHalfWidth() < XBORDER){
      player2->incScore();
      scoreBoard[1]++;
      ball->reset(2);
    }
    ///// Score against right, point to left (player 1)
  }else{
    if(*(ball->getPos()) + ball->getHalfWidth() > SCREEN_WIDTH - XBORDER){
      player1->incScore();
      scoreBoard[0]++;
      ball->reset(1);
    }
  }
}
