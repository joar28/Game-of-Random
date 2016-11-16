//
// Created by joar on 11/4/16.
//

#include <iostream>
#include "StateMainMenu.h"
#include "../globals.h"
#include "StateGame.h"

StateMainMenu::StateMainMenu() {
    std::cout << "Main menu state started." << std::endl;

    text_heading.setFont(global_game_resources->getPlayfair_regular());
	text_heading.setString("Game of Random");
	text_heading.setCharacterSize(55);
	text_heading.setColor(sf::Color::White);
	text_heading.setPosition(70,20);


    Ballen.setPosition(20.f, 20.f);
    Ballen.setFillColor(sf::Color::Green);
    Ballen.setRadius(5.f);

    addMenuText("Start", "start_game");
    addMenuText("Exit", "exit");

}

void StateMainMenu::Draw(sf::RenderWindow &window) {
    window.draw(text_heading);

    for(auto text : menuText){
        window.draw(*text.first);
    }

    window.draw(Ballen);
    window.display();
}
void StateMainMenu::Process(sf::Time DeltaTime) {

}
StateInterface::StateSwitcherData StateMainMenu::NextState() {
    if (next_state_data.next_state_ptr != this){
        StateInterface::StateSwitcherData tmp = next_state_data;
        next_state_data.next_state_ptr = this;
        for(auto text : menuText){
                    text.first->setColor(sf::Color::White);
                    text.first->setCharacterSize(30);
            }
        return tmp;
    }
    return next_state_data;
}

void StateMainMenu::Event(sf::Event *event) {
    switch (event->type){
        case (sf::Event::MouseMoved):
            for(auto text : menuText){
                if(text.first->getGlobalBounds().contains(event->mouseMove.x,event->mouseMove.y)){
                    if (text.first->getColor() != sf::Color::Yellow){
                        global_game_resources->playSound(ResourceLoader::sfxMenuClickBlip);
                    }
                    text.first->setColor(sf::Color::Yellow);
                    text.first->setCharacterSize(38);
                } else {
                    text.first->setColor(sf::Color::White);
                    text.first->setCharacterSize(30);
                }
            }
            break;
        case(sf::Event::MouseButtonPressed):
            for(auto text : menuText){
                if(text.first->getGlobalBounds().contains(sf::Mouse::getPosition(*global_game_resources->getWindow()).x, sf::Mouse::getPosition(*global_game_resources->getWindow()).y)){
                    menuChoiceAction(text.second);
                }
            }
            break;
        default:
            break;
    }
}

void StateMainMenu::addMenuText(std::string text, std::string actionString) {
    sf::Text* tmpText = new sf::Text(text, global_game_resources->getOpensans_regular(), 30);
    tmpText->setPosition(70,100+(menuText.size()*40));
    menuText.emplace(tmpText, actionString);

}


void StateMainMenu::menuChoiceAction(std::string actionString) {
    if(actionString == "start_game"){
        next_state_data.next_state_ptr = new StateGame();
    }else if(actionString == "exit"){
        std::cout << "Action exit: " << actionString << ". Exiting." << std::endl;
        next_state_data.next_state_ptr = nullptr;
    }else{
        std::cout << "Action not implemented: " << actionString << std::endl;

    }
}
