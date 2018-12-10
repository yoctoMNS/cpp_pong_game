#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Ball.hpp"


Ball::Ball(int x, int y)
{
  srand((unsigned int)time(NULL));
  this->x = originalX = x;
  this->y = originalY = y;
  direction = BALL_STOP;
}


void Ball::reset()
{
  x = originalX;
  y = originalY;
  direction = BALL_STOP;
}


void Ball::move()
{
  switch (direction)
    {
    case BALL_STOP:
      break;
    case BALL_UP:
      --y; break;
    case BALL_DOWN:
      ++y; break;
    case BALL_LEFT:
      --x; break;
    case BALL_LEFT_UP:
      --x; --y; break;
    case BALL_LEFT_DOWN:
      --x; ++y; break;
    case BALL_RIGHT:
      ++x; break;
    case BALL_RIGHT_UP:
      ++x; --y; break;
    case BALL_RIGHT_DOWN:
      ++x; ++y; break;
    default:
      break;
    }
}


void Ball::setRandomDirection()
{
  direction = (BallDirection)(rand()%3 + 5);
}


void Ball::directionChange(BallDirection d)
{
  direction = d;
}


void Ball::reflection(int width, int height)
{
  std::cout << (isCollisionWall(width, height)?"true":"false") << std::endl;
  if (isCollisionWall(width, height))
    {
      switch (direction)
        {
        case BALL_LEFT_DOWN:
          direction = BALL_LEFT_UP; break;
        case BALL_LEFT_UP:
          direction = BALL_LEFT_DOWN; break;
        case BALL_RIGHT_DOWN:
          direction = BALL_RIGHT_UP; break;
        case BALL_RIGHT_UP:
          direction = BALL_RIGHT_DOWN; break;
        }
    }

  if (isCollisionSideWall(width, height))
    {
      switch (direction)
        {
        case BALL_LEFT_DOWN:
          direction = BALL_RIGHT_UP; break;
        case BALL_LEFT_UP:
          direction = BALL_RIGHT_DOWN; break;
        case BALL_RIGHT_DOWN:
          direction = BALL_LEFT_UP; break;
        case BALL_RIGHT_UP:
          direction = BALL_LEFT_DOWN; break;
        }
    }
}


bool Ball::isCollisionWall(int width, int height)
{
  return (x <= 0) || (x >= width-1) ||
    (y <= 0) || (y >= height-1);
}


bool Ball::isCollisionSideWall(int width, int height)
{
  return (x <= 0) || (x >= width-1);
}
