/* Copyright
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include <iostream>
#include "Game.h"
#include "lua.h"
#include <lua5.3/lua.hpp>




int main() {
// lua test:
//    execute("lua/callback.lua");
//    return 0;

    std::cout << "Starting Game of Random" << std::endl;
    srand((uint32_t)time(NULL));
    Game game;

    if (!game.Init()) {
        std::cout << "Failed to initialize the Game. Quitting." << std::endl;
        return -1;
    }
    game.Run();

    return 0;
}


