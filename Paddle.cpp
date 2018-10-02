#include "Paddle.h"
#include "Game.h"
Paddle::Paddle(int player){

  height = (SCREEN_HEIGHT / 4) ;
  width = (SCREEN_WIDTH / 20) ;

  yPos = SCREEN_HEIGHT / 2;
  if(player == 1)
    xPos = XBORDER + (width);
  else
    xPos = SCREEN_WIDTH - XBORDER - (width);

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
  for(int i = XBORDER; i < SCREEN_WIDTH - XBORDER; i++){
    for(int j = YBORDER; j < SCREEN_HEIGHT - YBORDER; j++){
      if(i > xPos - (width/2) && i < xPos + (width/2)){
	if(j > yPos - (height/2) && j < yPos + (height/2)){
	  SDL_RenderDrawPoint(r,i,j);
	}
      }
    }

  }

}
