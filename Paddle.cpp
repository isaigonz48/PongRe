#include "Paddle.h"

Paddle::Paddle(){

  yPos = 0;
  if(player == 1)
    xPos = -20;
  else
    xPos = 20;

}

void Paddle::move(int up){

  if(up)
    yPos += 2;
  else
    yPos -=2;
  
  
}

void Paddle::reset(){

  yPos = 0;

}
