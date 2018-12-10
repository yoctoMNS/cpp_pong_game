#ifndef INCLUDED_GAME_MANAGER_HPP
#define INCLUDED_GAME_MANAGER_HPP


#include "Ball.hpp"
#include "Paddle.hpp"


class GameManager
{
private:
  int width, height;
  int score;
  bool gameEnd;
  Ball* ball;
  Paddle* player;
  Paddle* player2;


public:
  GameManager(int w, int h);


private:
  void initVariable();
  void buildInstance();
  void ballCollision();
  void input();
  void draw();
  bool isPlayerDraw(int x, int y);


public:
  void run();
};


#endif // !#ifndef INCLUDED_GAME_MANAGER_HPP
