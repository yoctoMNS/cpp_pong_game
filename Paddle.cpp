#include "Paddle.hpp"


Paddle::Paddle(int x, int y)
{
  this->x = originalX = x;
  this->y = originalY = y;
}


void Paddle::reset()
{
  x = originalX;
  y = originalY;
}
