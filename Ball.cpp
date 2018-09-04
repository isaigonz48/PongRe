#include Ball.h

Ball::Ball(){

  pos = {0,0};
  int yVel = 2;
  int xVel = 4;

}

int[] Ball::getPos(){

  return pos;

}

int Ball::bounce(Player **players){

  int absX = pos[0];
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
  }
  
  return 1;

  // prob done on Game

}

void Ball::score(Player **players){
  
  if(xVel < 0)
    players[1]->incScore();
  else
    players[0]->incScore();// prob done on Game

}

void Ball::paddleBounce(Player* p){
  //int padPos = p->getPaddlePos();
  //int pSize = p->getSize();
  int padTop = p->getPaddlePos() + (p->getHeight() / 2);
  int padBot = p->getPaddlePos() = (p->getHeight() / 2);
  if(pos[1] < padTop && pos[1] > padBot)
    xVel = -xVel;
}
