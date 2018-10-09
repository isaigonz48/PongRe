#ifndef Border_included
#define Border_included

#include <SDL2/SDL.h>

class Border{

 private:
  int width;
  int height;
  //char resizeFlag;
  int pos[2];
  int leftBound;
  int upBound;
  
 public:
  Border(int maxWidth, int maxHeight, int xPos, int yPos);
  ~Border();
  
  void draw(SDL_Renderer *renderer);
  void resize(int maxWidth, int maxHeight);

};

#endif
