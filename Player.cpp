#include "Player.h"
//#include "Paddle.h"

Player::Player(int n){

  paddle = new Paddle(n);
  /*height = YBORDER / 4;
  width = XBORDER / 20;*/
  score = 0;

}

Player::~Player(){

  paddle->~Paddle();
  //IMG_Quit();

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

void Player::drawPaddle(SDL_Renderer *r){

  paddle->draw(r);

}
