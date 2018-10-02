#ifndef PADDLE_INCLUDED
#define PADDLE_INCLUDED

#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
class Paddle{

 protected:
  int yPos;
  int xPos;
  int width;
  int height;
  
 public:
  Paddle(int player);
  ~Paddle();

  void move(char dir);
  void resetPos();
  int getYPos();
  int getXPos();
  int getHalfWidth(){ return width;}
  int getHalfHeight(){ return height;}

  void draw(SDL_Renderer *renderer);
};

#endif
