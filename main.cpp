#include "Game.h"


Game *game;

int main(int argc, char *argv[]){
  game = new Game();

  game->execute();

  game->cleanUp();
}
