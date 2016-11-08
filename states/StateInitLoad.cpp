/* Copyright 2016 Joar A. Etterlid
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include "StateInitLoad.h"
#include "StateMainMenu.h"

StateInitLoad::StateInitLoad(){
    Ballen.setPosition(20.f, 20.f);
    Ballen.setFillColor(sf::Color::Green);
    Ballen.setRadius(5.f);
    Speed = sf::Vector2f(15, 15);
    Clock.restart();
}

void StateInitLoad::Draw(sf::RenderWindow &window) {
    window.draw(Ballen);
}

void StateInitLoad::Process(sf::Time DeltaTime) {
    Ballen.move(Speed*DeltaTime.asSeconds());

}

StateInterface::StateSwitcherData * StateInitLoad::NextState() {
    if (Clock.getElapsedTime().asSeconds() >= 0.5){
        next_state_data.next_state_ptr = new StateMainMenu();
        next_state_data.delete_self = true;
    }
    return &next_state_data;
}


StateInitLoad::~StateInitLoad() {

}

void StateInitLoad::Event(sf::Event *event) {

}
