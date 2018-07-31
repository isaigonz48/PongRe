#ifndef BALL_INCLUDED
#define BALL_INCLUDED

class Ball{

 protected:

  int pos[2];
  int xVel;
  int yVel;
  
 public:

  Ball();
  ~Ball();
  
  int[] getPos();
  
  void hit();
  void score();

};

#endif
