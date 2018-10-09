#include "Border.h"

Border::Border(int maxW, int maxH, int x, int y){
  
  width = maxW - maxW / 5;
  height = maxH - maxH / 5;
  //resizeFlag = 0;
  pos[0] = x;
  pos[1] = y;
  leftBound = pos[0] - width/2;
  upBound = pos[1] - height/2;
}
 
Border::~Border(){
  
  
  
}

void Border::draw(SDL_Renderer *r){
  
  SDL_SetRenderDrawColor(r,255,255,255,255);
  //rightBound = pos[0] + height/2;
  for(int i = leftBound; i <= leftBound + width; i++){
    for(int j  = upBound; j <= upBound + height; j++){
      if(i == leftBound || i == leftBound + width || j == upBound || j == upBound + height){
	SDL_RenderDrawPoint(r,i,j);
      }
    }
  }
}
 
void Border::resize(int maxW, int maxH){
  
  width = maxW - maxW / 5;
  height = maxH - maxH / 5;
  //resizeFlag = 0;
  //pos[0] = x;
  //pos[1] = y;
  //leftBound = pos[0] - width/2;
  //upBound = pos[1] - height/2;
  

}
