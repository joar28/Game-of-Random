//
// Created by joar on 11/5/16.
//

#include "ObjectParticleBall.h"
#include "../globals.h"
#include "../VectorMath.h"

ObjectParticleBall::ObjectParticleBall(sf::Vector2f position, float radius) {
    setShape(new sf::CircleShape(radius));
    ((sf::CircleShape*)getShape())->setPosition(position);
    setShape_type(shape_circle);
}

void ObjectParticleBall::draw(sf::RenderWindow &window) {
    window.draw(*getShape());

}

void ObjectParticleBall::process(sf::Time time) {
    getShape()->move(getSpeed()*time.asSeconds());

    // Check collision of right screen edge
    if(((sf::CircleShape*)getShape())->getPosition().x + (((sf::CircleShape*)getShape())->getRadius()*2) > global_game_resources->getWindow()->getSize().x){
        setSpeed(sf::Vector2f(getSpeed().x*-1, getSpeed().y));
        setPosition(sf::Vector2f(global_game_resources->getWindow()->getSize().x-(((sf::CircleShape*)getShape())->getRadius()*2), getPosition().y));
    }

    // Check collision of left screen edge
    if (getPosition().x < 0){
        setSpeed(sf::Vector2f(getSpeed().x*-1, getSpeed().y));
        setPosition(sf::Vector2f(0,getPosition().y));
    }

    // Check collision of bottom screen edge
    if(((sf::CircleShape*)getShape())->getPosition().y + (((sf::CircleShape*)getShape())->getRadius()*2) > global_game_resources->getWindow()->getSize().y){
        setSpeed(sf::Vector2f(getSpeed().x, getSpeed().y*-1));
        setPosition(sf::Vector2f(getPosition().x, global_game_resources->getWindow()->getSize().y-(((sf::CircleShape*)getShape())->getRadius()*2)));
    }

    // Check collision of bottom screen edge
    if (getPosition().y < 0){
        setSpeed(sf::Vector2f(getSpeed().x, getSpeed().y*-1));
        setPosition(sf::Vector2f(getPosition().x, 0));
    }

}

float ObjectParticleBall::getRadius() const {
    return ((sf::CircleShape*)getShape())->getRadius();
}

void ObjectParticleBall::setRadius(float radius) {
    ((sf::CircleShape*)getShape())->setRadius(radius);
}

void ObjectParticleBall::proximityControl(ObjectInterface *test_object) {

    float distance = vm::distance<float>(getCenterPosition(), test_object->getCenterPosition());

    if (distance < 100){
        // Position of object in proximity
        sf::Vector2f test_pos = test_object->getCenterPosition();

        // Position of self
        sf::Vector2f this_pos = getCenterPosition();

        // Speed modifier
        sf::Vector2f speed_modifier = getCenterPosition();

        float flipped_distance = (100 - distance) / 1000;
        speed_modifier.x *= flipped_distance;
        speed_modifier.y *= flipped_distance;


        setSpeed(getSpeed()+speed_modifier);

    }

}
