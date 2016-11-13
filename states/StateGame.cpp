//
// Created by joar on 11/5/16.
//

#include <iostream>
#include "StateGame.h"
#include "../objects/ObjectParticleBall.h"
#include "../globals.h"
#include "../objects/ObjectNewParticleLine.h"
#include "../objects/ObjectLeftSideBar.h"
#include "../objects/ObjectButton.h"


StateGame::StateGame() {
    int speed = 5;
    ObjectList.push_front(new ObjectLeftSideBar(global_game_resources->getLeft_side_bar_size()));
    add_button("Typ", std::bind(&StateGame::callback_typ, this));
//    add_button("asd");
//    add_button("czxcv");
    for (int i = 0; i < 10; i++){
        ObjectList.push_front(new ObjectParticleBall(
                sf::Vector2f(
                        rand() % global_game_resources->getWindow()->getSize().x - 10,
                        rand() % global_game_resources->getWindow()->getSize().y - 10),
                5, 2));
        ObjectList.front()->getShape()->setFillColor(sf::Color::Green);
        ObjectList.front()->setSpeed(sf::Vector2f((rand()%speed*2)-speed,(rand()%speed*2)-speed));
//        ObjectList.front()->setSpeed(sf::Vector2f(1,1));
    }

/*
    ObjectList.push_front(new ObjectParticleBall(sf::Vector2f((global_game_resources->getWindow()->getSize().x/2) -100, global_game_resources->getWindow()->getSize().y/2), 5));
    ObjectList.front()->getShape()->setFillColor(sf::Color::Green);
    ObjectList.front()->setSpeed(sf::Vector2f(10,2));

    ObjectList.push_front(new ObjectParticleBall(sf::Vector2f((global_game_resources->getWindow()->getSize().x/2) +100,global_game_resources->getWindow()->getSize().y/2), 5));
    ObjectList.front()->getShape()->setFillColor(sf::Color::Green);
    ObjectList.front()->setSpeed(sf::Vector2f(-10,0));
*/

/*

    ObjectList.push_front(new ObjectParticleBall(sf::Vector2f((global_game_resources->getWindow()->getSize().x/2),(global_game_resources->getWindow()->getSize().y/2)+100), 5));
    ObjectList.front()->getShape()->setFillColor(sf::Color::Green);
    ObjectList.front()->setSpeed(sf::Vector2f(0,-10));

    ObjectList.push_front(new ObjectParticleBall(sf::Vector2f((global_game_resources->getWindow()->getSize().x/2),(global_game_resources->getWindow()->getSize().y/2)-100), 5));
    ObjectList.front()->getShape()->setFillColor(sf::Color::Green);
    ObjectList.front()->setSpeed(sf::Vector2f(0,10));
*/

}

void StateGame::add_button(std::string text, std::function<int()> cb) {
    static int next_button_pos = 10;
    ObjectList.push_back(new ObjectButton(sf::Vector2f(10, next_button_pos),
                                          text,
                                          cb));
    next_button_pos += 40;
}

int StateGame::callback_typ(){
    std::cout << "Typ button pressed" << std::endl;
    return 0;
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

    switch (event->type){
        case sf::Event::Closed:break;
        case sf::Event::Resized:break;
        case sf::Event::LostFocus:break;
        case sf::Event::GainedFocus:break;
        case sf::Event::TextEntered:break;
        case sf::Event::KeyPressed:  KeyPressed(event);  break;
        case sf::Event::KeyReleased: KeyReleased(event); break;
        case sf::Event::MouseWheelMoved:break;
        case sf::Event::MouseWheelScrolled:break;
        case sf::Event::MouseButtonPressed:  MouseButtonPressed(event);  break;
        case sf::Event::MouseButtonReleased: MouseButtonReleased(event); break;
        case sf::Event::MouseMoved:break;
        case sf::Event::MouseEntered:break;
        case sf::Event::MouseLeft:break;
        case sf::Event::JoystickButtonPressed:break;
        case sf::Event::JoystickButtonReleased:break;
        case sf::Event::JoystickMoved:break;
        case sf::Event::JoystickConnected:break;
        case sf::Event::JoystickDisconnected:break;
        case sf::Event::TouchBegan:break;
        case sf::Event::TouchMoved:break;
        case sf::Event::TouchEnded:break;
        case sf::Event::SensorChanged:break;
        case sf::Event::Count:break;
    }
}

void StateGame::KeyPressed(sf::Event *event) {

}

void StateGame::KeyReleased(sf::Event *event) {

}

void StateGame::MouseButtonPressed(sf::Event *event) {
    sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(*global_game_resources->getWindow()));

    if (   (mouse_pos.x > global_game_resources->getLeft_side_bar_size())
//        && (mouse_pos.x > global_game_resources->getRight_side_bar_size())
            ){
        if (event->mouseButton.button == sf::Mouse::Left) {
            first_mouse_release = false;
            mouse_last_pressed = sf::Vector2f(sf::Mouse::getPosition(*global_game_resources->getWindow()));

            ObjectList.push_front(new ObjectNewParticleLine(mouse_pos));
            mouse_pos -= sf::Vector2f(5.f, 5.f);

            ObjectList.push_front(new ObjectParticleBall(mouse_pos, 5, 2));
            ObjectList.front()->getShape()->setFillColor(sf::Color::Blue);

        }
    } else {
        for (auto* object : ObjectList){
            if(object->IsClickable()){
                ((ObjectClickable*)object)->checkClick(event);
            }
        }
    }
}

void StateGame::MouseButtonReleased(sf::Event *event) {
    sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(*global_game_resources->getWindow()));
    if (   (mouse_pos.x > global_game_resources->getLeft_side_bar_size())
//        && (mouse_pos.x > global_game_resources->getRight_side_bar_size())
            ){
        if(!first_mouse_release){
            if(event->mouseButton.button == sf::Mouse::Left){
                ObjectList.front()->setSpeed(mouse_last_pressed - mouse_pos);
                ObjectInterface* objectDelete = nullptr;
                bool finnished = true;
                while(finnished){
                    for(auto &object : this->ObjectList){
                        if(object->getShape_type() == ObjectInterface::ShapeType::shape_line){
                            objectDelete = object;
                            object->~ObjectInterface();
                            break;
                        }
                        finnished = false;
                    }
                    ObjectList.remove(objectDelete);
                }
            }
        }
    }
}
