//
// Created by joar on 11/5/16.
//

#include <iostream>
#include "StateGame.h"
#include "../objects/ObjectParticleBall.h"
#include "../globals.h"

sf::Color random_color(){
    

}

StateGame::StateGame() {
    for (int i = 0; i < 100; i++){
        ObjectList.push_front(new ObjectParticleBall(sf::Vector2f(rand()%global_game_resources->getWindow()->getSize().x-10,rand()%global_game_resources->getWindow()->getSize().y-10), 5));
        ObjectList.front()->getShape()->setFillColor(sf::Color::Green);
        ObjectList.front()->setSpeed(sf::Vector2f((rand()%40)-20,(rand()%40)-20));
//        ObjectList.front()->setSpeed(sf::Vector2f(1,1));
    }
}


void StateGame::Draw(sf::RenderWindow &window) {
    for(auto& object : this->ObjectList){
        object->draw(window);
    }

}

void StateGame::Process(sf::Time DeltaTime) {

    for(auto &object : this->ObjectList){
        for(auto &inner_object : this->ObjectList){
            if(object != inner_object){
                object->proximityControl(inner_object);
            }
        }
    }


    for(auto &object : this->ObjectList){
        object->process(DeltaTime);
    }

}

StateInterface::StateSwitcherData *StateGame::NextState() {
    return &next_state_data;
}

void StateGame::Event(sf::Event *event) {

}