#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include Paddle.h

class Player{

 protected:
  Paddle *paddle;
  int height;
  int width;
  int score;
  
 public:
  Player(int n);
  ~Player();

  int getScore();

  void incScore();

  int getPaddlePos();
  int getHeight();
  int getWidth();
};

#endif
