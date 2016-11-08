/* Copyright
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */


#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <stack>
#include "states/StateInterface.h"
#include "ResourceLoader.h"

// /Main game class.
class Game {
  public:
    // /Initialize game stuff.
    bool Init();

    // /Main game loop
    void Run();

  private:
    StateInterface::StateSwitcherData next_state_data;
//    StateInterface *next_state_data;
    sf::RenderWindow window;
    std::stack<StateInterface *> gameStateStack;
    sf::Clock clock;


};

#endif  // GAME_H_
