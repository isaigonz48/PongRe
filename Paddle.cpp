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


void Paddle::move(char dir){

  if(dir == 0)
    ;
  else if(dir == -1 && yPos + (height / 2)< SCREEN_HEIGHT - YBORDER)
    yPos += 5;
  else if (dir == 1 && yPos - (height / 2)> YBORDER)
    yPos -= 5;
  
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

int Paddle::getHalfWidth(){
  
  return width/2;

}

int Paddle::getHalfHeight(){

  return height/2;
  
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
