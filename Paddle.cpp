#include "Paddle.h"

Paddle::Paddle(){

  yPos = 0;
  if(player == 1)
    xPos = -20;
  else
    xPos = 20;

  height = (YBORDER / 4) / 2;
  width = (XBORDER / 20) / 2;
}

void Paddle::move(int up){

  if(up)
    yPos += 2;
  else
    yPos -=2;
  
  
}

void Paddle::resetPos(){

  yPos = 0;

}

int Paddle::getYPos(){

  return yPos;
  
}

int Paddle::getXPos(){

  return xPos;

}
