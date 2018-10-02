#ifndef BALL_INCLUDED
#define BALL_INCLUDED

//#include "Game.h"
//#include "Player.h"
//#include "Game.h"
#include <SDL2/SDL.h>
class Ball{

 protected:

  int pos[2];
  int xVel;
  int yVel;
  int halfWidth;
  //int halfHeight;
  
 public:

  Ball();
  ~Ball();
  
  int* getPos();
  int getXVel();
  int getYVel();
  int getHalfWidth(){ return halfWidth;}
  //int getHalfHeight(){ return halfHeight;}
    /*void bounce(Player **players);
  int score(Player **players);
  void paddleBounce(Player *p);
    */
  void move();
  void bounce(char dir);
  void reset(char winner);
  //void paddleBounce(Player *p);

  void draw(SDL_Renderer *renderer);
};

#endif
