#include <ctime>
#include <cstdlib>
#include <iostream>
#include "GameManager.hpp"


int main()
{
  GameManager game(40, 20);
  game.run();

  return 0;
}
