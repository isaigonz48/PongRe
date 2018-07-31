#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include Paddle.h

class Player{

 protected:
  Paddle *paddle;
  int score;
  
 public:
  Player(int n);
  ~Player();

  int getScore();

  void incScore();
};

#endif
