//
// Created by joar on 11/13/16.
//

#include <iostream>
#include "ObjectButton.h"
#include "../globals.h"

ObjectButton::ObjectButton(const sf::Vector2f &position, std::string text_s, std::function<int()> cb)
        :
        ObjectClickable(
                ObjectInterface::ShapeType::shape_rectangle,
                DerivedClassType::object_button,
                true),
        text_string(text_s)
{
    callback = cb;

    background.setSize(sf::Vector2f(80,30));
    background.setPosition(position);
    background.setFillColor(sf::Color(80, 0, 0));
    background.setOutlineColor(sf::Color(40,40,40));
    background.setOutlineThickness(2);

    sf::Vector2f text_position = position;
    text_position.x += background.getGlobalBounds().width/2;
    text_position.y += 2;
    text.setString(text_string);
    text.setFont(global_game_resources->getPlayfair_regular());
    text.setCharacterSize(20);
    text_position.x -= text.getGlobalBounds().width/2;
    text.setPosition(text_position);

}

void ObjectButton::draw(sf::RenderWindow &window) {
    window.draw(background);
    window.draw(text);
}

void ObjectButton::process(sf::Time time) {

}

void ObjectButton::proximityControl(ObjectInterface *test_object) {

}

void ObjectButton::checkClick(sf::Event *event) {
    sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(*global_game_resources->getWindow()));
    if((background.getGlobalBounds().contains(mouse_pos))){
        int number = callback();
        std::cout << number << std::endl;
    }
}

ObjectButton::~ObjectButton() {

}

