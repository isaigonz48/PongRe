#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <SDL2/SDL.h>
#include <stdio.h>

class Game{

 protected:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  
 public:
  Game();
  ~Game();
  
  int execute();
  void init(const char*, int xpos, int ypos, int width, int height, bool full);
  void handleEvents();
  void loop();
  void render();
  void cleanUp();
  
  bool running(){return isRunning;}
};

#endif
