#include "Player.h"

Player::Player(int n){

  paddle = new Paddle(n);
  score = 0;

}

int Player::getScore(){

  return score;

}

void Player::incScore(){

  score++;

}
