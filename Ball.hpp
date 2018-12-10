#ifndef INCLUDED_BALL_HPP
#define INCLUDED_BALL_HPP


enum BallDirection
  {
   BALL_STOP=0,
   BALL_UP,
   BALL_DOWN,
   BALL_LEFT,
   BALL_RIGHT,
   BALL_LEFT_UP,
   BALL_LEFT_DOWN,
   BALL_RIGHT_UP,
   BALL_RIGHT_DOWN,
  };


class Ball
{
private:
  int x, y;
  int originalX, originalY;
  BallDirection direction;


public:
  Ball(int x, int y);


public:
  void reset();
  void move();
  void setRandomDirection();
  void directionChange(BallDirection d);
  void reflection(int width, int height);
  bool isCollisionWall(int width, int height);
  bool isCollisionSideWall(int width, int height);
  

public:
  inline int getX() { return x; }
  inline int getY() { return y; }
  inline int getDirection() { return direction; }
};


#endif // !#ifndef INCLUDED_BALL_HPP
