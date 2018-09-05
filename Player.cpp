#include "Player.h"

Player::Player(int n){

  paddle = new Paddle(n);
  /*height = YBORDER / 4;
  width = XBORDER / 20;*/
  score = 0;

}

int Player::getScore(){

  return score;

}

void Player::incScore(){

  score++;

}

Paddle* Player::getPaddle(){

  return paddle;
  
}

int Player::getHeight(){

  return height;

}

int Player::getWidth(){

  return width;

}

void Player::move(){



}
