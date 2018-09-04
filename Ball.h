#ifndef BALL_INCLUDED
#define BALL_INCLUDED

#include "Game.h"

class Ball{

 protected:

  int pos[2];
  int xVel;
  int yVel;
  
 public:

  Ball();
  ~Ball();
  
  int[] getPos();
  
  void bounce(Player **players);
  int score(Player **players);
  void paddleBounce(Player *p);
};

#endif
