#ifndef PADDLE_INCLUDED
#define PADDLE_INCLUDED

class Paddle{

 protected:
  int yPos;
  int xPos;
  int width;
  int height;
  
 public:
  Paddle(int player);
  ~Paddle();

  void move(int up);
  void resetPos();
  int getYPos();
  int getXPos();
  int getHalfWidth(){ return width;}
  int getHalfHeight(){ return height;}
};

#endif
