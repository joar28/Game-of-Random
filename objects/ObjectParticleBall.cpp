//
// Created by joar on 11/5/16.
//

#include "ObjectParticleBall.h"
#include "../globals.h"
#include "../VectorMath.h"



ObjectParticleBall::ObjectParticleBall(sf::Vector2f position, float radius, int type) {
    setShape(new sf::CircleShape(radius));
    ((sf::CircleShape*)getShape())->setPosition(position);
    setShape_type(shape_circle);
    behavior = type;
}

void ObjectParticleBall::draw(sf::RenderWindow &window) {
    window.draw(*getShape());
}

void ObjectParticleBall::process(sf::Time time) {
    getShape()->move(getSpeed()*time.asSeconds());

    // Check collision of right screen edge
    if(((sf::CircleShape*)getShape())->getPosition().x + (((sf::CircleShape*)getShape())->getRadius()*2) > global_game_resources->getWindow()->getSize().x - global_game_resources->getRight_side_bar_size()){
        setSpeed(sf::Vector2f(getSpeed().x*-1, getSpeed().y));
        setPosition(sf::Vector2f(global_game_resources->getWindow()->getSize().x-(((sf::CircleShape*)getShape())->getRadius()*2), getPosition().y - global_game_resources->getRight_side_bar_size()));
    }

    // Check collision of left screen edge
    if (getPosition().x < 0+global_game_resources->getLeft_side_bar_size()){
        setSpeed(sf::Vector2f(getSpeed().x*-1, getSpeed().y));
        setPosition(sf::Vector2f(global_game_resources->getLeft_side_bar_size(),getPosition().y));
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

    if(vm::speed<float>(getSpeed()) > 200){
        setSpeed(sf::Vector2f((rand()%20)/10, (rand()%20)/10));
    }

}

float ObjectParticleBall::getRadius() const {
    return ((sf::CircleShape*)getShape())->getRadius();
}

void ObjectParticleBall::setRadius(float radius) {
    ((sf::CircleShape*)getShape())->setRadius(radius);
}


void ObjectParticleBall::type_1(ObjectInterface *test_object) {
    float distance = vm::distance<float>(getCenterPosition(), test_object->getCenterPosition());
    if (distance < 100){
        // Position of object in proximity
        // sf::Vector2f test_pos = test_object->getCenterPosition();
        sf::Vector2f test_speed = test_object->getSpeed();

        // Position of self
        // sf::Vector2f this_pos = getCenterPosition();
        sf::Vector2f this_speed = getSpeed();

        if(getSpeed().x > 100){
            this_speed.x = (rand()%20)/10;
            setSpeed(this_speed);
        }

        if(getSpeed().y > 100){
            this_speed.y = (rand()%20)/10;
            setSpeed(this_speed);
        }

        // Speed modifier
        sf::Vector2f speed_modifier = sf::Vector2f(this_speed.x/100, this_speed.y/100);

        test_object->setSpeed(test_speed+speed_modifier);

        //setSpeed(getSpeed()-speed_modifier);

    }
}

void ObjectParticleBall::type_2(ObjectInterface *test_object) {
    float distance = vm::distance(getCenterPosition(), test_object->getCenterPosition());
    if (distance < 100){
        // Position of object in proximity
        // sf::Vector2f test_pos = test_object->getCenterPosition();
        sf::Vector2f test_speed = test_object->getSpeed();

        // Position of self
        // sf::Vector2f this_pos = getCenterPosition();
        sf::Vector2f this_speed = getSpeed();

        // Speed modifier
        sf::Vector2f speed_modifier = sf::Vector2f(this_speed.x/100, this_speed.y/100);

        test_object->setSpeed(test_speed+speed_modifier);

        //setSpeed(getSpeed()-speed_modifier);
    }
}


void ObjectParticleBall::proximityControl(ObjectInterface *test_object) {

    if(test_object->getShape_type() == ObjectInterface::ShapeType::shape_circle){
        if (behavior == 1){
            type_1(test_object);
        }else if (behavior == 2){
            type_2(test_object);
        }
    }
}
