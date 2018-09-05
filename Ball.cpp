#include "Ball.h"

Ball::Ball(){

  pos = {0,0};
  int yVel = 2;
  int xVel = 4;

}

int* Ball::getPos(){

  return &pos[0];

}

int Ball::getXVel(){
  return xVel;
}

int Ball::getYVel(){

  return yVel;
  
}

void Ball::move(){

  pos[0] += xVel;
  pos[1] += yVel;

}
int Ball::bounce(char dir){

  /*int absX = pos[0];
  if(absX < 0)
    absX = -absX;

  int absY = pos[1];
  if(absY < 0)
    absY = -absY;

  if(absY >= YBORDER){
    yVel = -yVel;
  }
  if(absX >= XBORDER){
    score(players);
    return 0;
  }
  if(absX > XBORDER - players[0]->getWidth){
    if(xVel < 0){
      paddleBounce(players[0]);
    }
    else if(xVel > 0){
      paddleBounce(players[1]);
    }
    }*/

  if(dir){
    yVel = -yVel;
  }else{
    xVel = -xVel;
  }
  
  return 1;

  // prob done on Game

}

void Ball::reset(char winner){
  pos[0] = 0;
  //pos[1] = 0;

  if(winner){
    xVel = -4;
  }else{
    xVel = 4;
  }
}
/*void Ball::score(Player **players){
  
  if(xVel < 0)
    players[1]->incScore();
  else
    players[0]->incScore();// prob done on Game

    }*/

/*void Ball::paddleBounce(Player* p){
  //int padPos = p->getPaddlePos();
  //int pSize = p->getSize();
  int padTop = p->getPaddlePos() + (p->getHeight() / 2);
  int padBot = p->getPaddlePos() = (p->getHeight() / 2);
  if(pos[1] < padTop && pos[1] > padBot)
    xVel = -xVel;
    }*/
