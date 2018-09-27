#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "Paddle.h"
#include <SDL2/SDL.h>
//#include "Game.h"

class Player{

 protected:
  Paddle *paddle;
  int height;
  int width;
  int score;
  
 public:
  Player(int n);
  ~Player();

  int getScore();

  void incScore();

  Paddle* getPaddle();
  int getHeight();
  int getWidth();

  void move();

  void drawPaddle(SDL_Renderer *renderer);
};

#endif
