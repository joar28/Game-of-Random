/* Copyright
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include "Game.h"    // NOLINT(build/include)
#include "states/StateInterface.h"
#include "states/StateInitLoad.h"
#include "globals.h"
#include <iostream>  // NOLINT(build/include)
#include <zconf.h>

ResourceLoader* global_game_resources;

bool Game::Init(){
    std::cout << "Game init." << std::endl;


    // Standard SFML setup
    window.create(sf::VideoMode(1200, 900), "Game of Random");

//    // Double the size of the screen
//    sf::View view = window.getDefaultView();
//    view.setSize(view.getSize().x / 2, view.getSize().y / 2);
//    view.setCenter(view.getCenter().x / 2, view.getCenter().y / 2);
//    window.setView(view);

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    global_game_resources = new ResourceLoader;
    global_game_resources->setWindow(&window);

    if(!global_game_resources->LoadResources()){
        return false;
    }
    //next_state_data = new StateInterface::StateSwitcherData;
    next_state_data.next_state_ptr = new StateInitLoad();
    gameStateStack.push(next_state_data.next_state_ptr);



    return true;
}

void Game::Run() {
    std::cout << "Game run." << std::endl;

    while (window.isOpen()) {
        // Event handling
        sf::Event event;

        while (window.pollEvent(event)) {
            gameStateStack.top()->Event(&event);
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                std::cout << "Window X close button pressed." << std::endl;
                while(gameStateStack.size()){
                    delete(gameStateStack.top());
                    gameStateStack.pop();
                }
                delete(global_game_resources);
                window.close();
                return;
            }
        }
        next_state_data = *gameStateStack.top()->NextState();
        if (next_state_data.next_state_ptr == nullptr) {    //popper øverste state på stacken for å gå tilbake til forrige state
            delete gameStateStack.top();
            gameStateStack.pop();
            std::cout << "GameState Popped!!" << std::endl;
            if (gameStateStack.size() == 0) {
                std::cout << "State stack empty. Quitting." << std::endl;
                delete(global_game_resources);
                return;
            }
        } else if (gameStateStack.top() == next_state_data.next_state_ptr) {    //Fortsett i samme state som før
            //std::cout << "GameState not changed" << std::endl;
        } else {   //Legg til ny gamestate øverst på state-stacken
            std::cout << "GameState Pushed!" << std::endl;
            if(next_state_data.delete_self){
                delete(gameStateStack.top());
                gameStateStack.pop();

            }
            gameStateStack.push(next_state_data.next_state_ptr);
        }

        //Få tiden siden sist frame ble tegnet.
        sf::Time time = clock.getElapsedTime();

        //Reset klokke for å bli klar til neste loop
        clock.restart().asMilliseconds();

        //Kjør process på aktiv state
        gameStateStack.top()->Process(time);

        //Nullstill vindu
//        window.clear(sf::Color(1,32,67));
        window.clear(sf::Color(0,0,0));

        //Aktiv state tegner på vindu
        gameStateStack.top()->Draw(window);

        //Vis tegnet vindu
        window.display();

    }  // end of window.isOpen loop
}
