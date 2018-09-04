#include "Player.h"

Player::Player(int n){

  paddle = new Paddle(n);
  height = YBORDER / 4;
  width = XBorder / 20;
  score = 0;

}

int Player::getScore(){

  return score;

}

void Player::incScore(){

  score++;

}

int Player::getPaddlePos(){

  return paddle->getPos();
  
}

int Player::getHeight(){

  return height;

}

int Player::getWidth(){

  return width;

}
