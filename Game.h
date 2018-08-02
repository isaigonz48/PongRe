#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <SDL2/SDL.h>
#include <stdio.h>

#include "Ball.h"
#include "Player.h"

final int SCREEN_WIDTH 800;
final int SCREEN_HEIGHT 600;

final int XBORDER (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 10);
final int YBORDER (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 10);


class Game{

 protected:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  Player *player1;
  Player *player2;
  Ball *ball;
  int xBorder;
  int yBorder;

  
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
