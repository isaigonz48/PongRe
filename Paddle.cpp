#include "Paddle.h"
#include "Game.h"
Paddle::Paddle(int player){

  yPos = 0;
  if(player == 1)
    xPos = -20;
  else
    xPos = 20;

  height = (YBORDER / 4) / 2;
  width = (XBORDER / 20) / 2;

  //IMG_Init(IMG_INIT_JPG)
}

Paddle::~Paddle(){

  //IMG_Quit();

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

void Paddle::draw(SDL_Renderer *r){

  SDL_SetRenderDrawColor(r, 255,255,255,255);
  for(int i = 0; i < XBORDER; i++){
    for(int j = 0; j < YBORDER; j++){
      if(i > xPos - width/2 && i < xPos + width/2){
	if(j > yPos - height/2 && j < yPos + height/2){
	  SDL_RenderDrawPoint(r,i,j);
	}
      }
    }

  }

}
