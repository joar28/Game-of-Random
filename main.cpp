/* Copyright
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include <iostream>
#include "Game.h"

int main() {
  std::cout << "Starting Game of Random" << std::endl;

  Game game;

  if (!game.Init()) {
    std::cout << "Failed to initialize the Game. Quitting." << std::endl;
    return -1;
  }

  game.Run();

  return 0;
}
