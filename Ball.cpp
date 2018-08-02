#include Ball.h

Ball::Ball(){

  pos = {0,0};
  int yVel = 2;
  int xVel = 4;

}

int[] Ball::getPos(){

  return pos;

}

void Ball::bounce(){

  int absX = pos[0];
  if(absX < 0)
    absX = -absX;

  int absY = pos[1];
  if(absY < 0)
    absY = -absY;
  if(absX >= XBORDER){
    score();
  }
  if(absY >= YBORDER){
    yVel = -yVel;
  }

  // prob done on Game

}

void Ball::score(){
  
  // prob done on Game

}
