#include "Player.h"
//#include "Paddle.h"

Player::Player(int n){

  paddle = new Paddle(n);
  nextLoc = 0;
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

  paddle->move(nextLoc);
  nextLoc = 0;
}

void Player::drawPaddle(SDL_Renderer *r){

  paddle->draw(r);

}

void Player::setNextLoc(char dir){

  if(dir == 1){
    nextLoc = 1;
  }else{
    nextLoc = -1;
  }
}
