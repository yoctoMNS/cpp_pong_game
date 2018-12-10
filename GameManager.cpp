#include <iostream>
#include <conio.h>
#include "GameManager.hpp"


const char PLAYER1_UP_KEY = 'w';
const char PLAYER1_DOWN_KEY = 's';
const char PLAYER2_UP_KEY = 'i';
const char PLAYER2_DOWN_KEY = 'k';


GameManager::GameManager(int w, int h)
  :width(w), height(h)
{
  initVariable();
  buildInstance();
}


void GameManager::initVariable()
{
  score = 0;
  gameEnd = false;
}


void GameManager::buildInstance()
{
  player = new Paddle(2, height/2-2);
  player2 = new Paddle(width-3, height/2-2);
  ball = new Ball(width/2, height/2);
}


void GameManager::input()
{
  if (_kbhit())
    {
      if (ball->getDirection() == BALL_STOP)
        ball->setRandomDirection();

      int py = player->getY();
      int p2y = player2->getY();
      
      switch (_getch())
        {
        case PLAYER1_UP_KEY:
          --py; break;
        case PLAYER1_DOWN_KEY:
          ++py; break;
        case PLAYER2_UP_KEY:
          --p2y; break;
        case PLAYER2_DOWN_KEY:
          ++p2y; break;
        }

      if (py <= 0) py = 0;
      if (py+5 > height-1) py = height-1;
      if (p2y <= 0) p2y = 0;
      if (p2y+5 > height-1) p2y = height-1;

      if (player->getY() != py)
        player->setY(py);
      else if (player2->getY() != p2y)
        player2->setY(p2y);

    }

  ball->reflection(width, height);
}


void GameManager::draw()
{
  system("cls");
 
  for (int i=0; i<width+2; ++i)
    std::cout << '#';
  std::cout << '\n';


  for (int i=0; i<height; ++i)
    {
      for (int j=0; j<width; ++j)
        {
          if (j == 0) std::cout << '#';

          if (j == ball->getX() && i == ball->getY())
            std::cout << 'o';
          else
            {
              if (!isPlayerDraw(j, i))
                std::cout << ' ';
            }

          if (j == width-1) std::cout << '#';
        }
      std::cout << '\n';
    }


  for (int i=0; i<width+2; ++i)
    std::cout << '#';
  std::cout << '\n';

  std::cout << "p1y: " << player->getY() << std::endl;
  std::cout << "p2x: " << player2->getY() << std::endl;


  std::cout << std::flush;
}


bool GameManager::isPlayerDraw(int x, int y)
{
  int px = player->getX();
  int py = player->getY();
  int p2x = player2->getX();
  int p2y = player2->getY();
  bool drawFlag = false;

  for (int i=0; i<5; ++i)
    {
      if (x == px && y == py+i)
        {
          std::cout << '|';
          drawFlag = true;
        }
      
      if (x == p2x && y == p2y+i)
        {
          std::cout << '|';
          drawFlag = true;
        }
    }

  return drawFlag;
}


void GameManager::run()
{
  while (!gameEnd)
    {
      draw();
      input();
      ball->move();
    }

  std::cout << "X: " << ball->getX() << std::endl;
  std::cout << "Y: " << ball->getY() << std::endl;
}
