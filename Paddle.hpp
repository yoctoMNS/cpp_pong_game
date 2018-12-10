#ifndef INCLUDED_PADDLE_HPP
#define INCLUDED_PADDLE_HPP


class Paddle
{
private:
  int x, y;
  int originalX, originalY;


public:
  Paddle(int x, int y);


public:
  void reset();


public:
  inline int getX() { return x; }
  inline int getY() { return y; }
  inline void setX(int x) { this->x = x; }
  inline void setY(int y) { this->y = y; }
};


#endif // !#ifndef INCLUDED_PADDLE_HPP
