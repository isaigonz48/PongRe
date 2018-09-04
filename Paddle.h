#ifndef PADDLE_INCLUDED
#define PADDLE_INCLUDED

class Paddle{

 protected:
  int yPos;
  int xPos;
  
 public:
  Paddle(int player);
  ~Paddle();

  void move(int up);
  void resetPos();
  int getPos();
};

#endif
