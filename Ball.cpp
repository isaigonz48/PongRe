#include "Ball.h"
#include "Game.h"

Ball::Ball(){

  pos[0] = SCREEN_WIDTH / 2;
  pos[1] = SCREEN_HEIGHT / 2;
  yVel = 3;
  xVel = 3;
  halfWidth = (SCREEN_WIDTH / 20) / 2;

}

Ball::~Ball(){

  

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
void Ball::bounce(char dir){

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
  
  // prob done on Game

}

void Ball::reset(char winner){
  pos[0] = SCREEN_WIDTH / 2;
  pos[1] = SCREEN_HEIGHT / 2;

  if(winner == 2){
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

void Ball::draw(SDL_Renderer *r){

  SDL_SetRenderDrawColor(r, 255,255,255,255);
  for(int i = XBORDER; i < (SCREEN_WIDTH - XBORDER); i++){
    for(int j = YBORDER; j < (SCREEN_HEIGHT - YBORDER); j++){
      if(i > pos[0] - halfWidth && i < pos[0] + halfWidth){
	  if(j > (pos[1] - halfWidth) && j < (pos[1] + halfWidth)){
	  SDL_RenderDrawPoint(r,i,j);
	}
      }
    }

  }

}
