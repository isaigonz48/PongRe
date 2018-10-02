#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "Ball.h"
#include "Player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define XBORDER ((SCREEN_WIDTH / 10))
#define YBORDER ((SCREEN_HEIGHT / 10))


class Game{

 protected:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *image;
  SDL_Texture *texture;
  Player *player1;
  Player *player2;
  Ball *ball;
  int scoreBoard[2];
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

  void checkBounce();
  void checkIfScore();
  //Player* getP1();
  //Player* getP2();
};

#endif
