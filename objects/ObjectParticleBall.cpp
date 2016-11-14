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
    crowd_death_level = 0;
    spawn_child_rate = 1000 + (rand()%5000);
}

void ObjectParticleBall::draw(sf::RenderWindow &window) {
    window.draw(*getShape());
}

void ObjectParticleBall::process(sf::Time DeltaTime) {
    if(is_alive){
        getShape()->move(getSpeed()*DeltaTime.asSeconds());
    } else {
        setSpeed(sf::Vector2f(0, 0));
        if(death_fade.getElapsedTime().asMilliseconds() < 3000){
            sf::Color temp_color = getShape()->getFillColor();

            temp_color.a = (sf::Uint8)255 - (sf::Uint8)((death_fade.getElapsedTime().asMilliseconds()/3000.f)*255.f);

            getShape()->setFillColor(temp_color);
        } else {
            setMarked_for_delete(true);
        }
    }

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

    if(behavior == 3){
        if((crowd_death_level > 400) && is_alive){
            this->getShape()->setFillColor(sf::Color::Yellow);
            setIs_alive(false);
            death_fade.restart();
        }
        if((crowd_death_level < 100 && is_alive) ){
            if(spawn_child.getElapsedTime().asMilliseconds() > spawn_child_rate){
                setGive_birth(true);
                spawn_child.restart();
            }
        } else {
            spawn_child.restart();
        }
    }
    crowd_death_level = 0;

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

void ObjectParticleBall::type_3(ObjectInterface *test_object) {
    float distance = vm::distance(getCenterPosition(), test_object->getCenterPosition());

    if (distance < 100){
        sf::Vector2f test_speed = test_object->getSpeed();
        sf::Vector2f this_speed = getSpeed();
        sf::Vector2f speed_modifier = sf::Vector2f(this_speed.x/100, this_speed.y/100);
        test_object->setSpeed(test_speed+speed_modifier);
        if(((ObjectParticleBall*)test_object)->is_alive){
            crowd_death_level += 100-distance;
        }


    }
}


void ObjectParticleBall::proximityControl(ObjectInterface *test_object) {

    if(test_object->getShape_type() == ObjectInterface::ShapeType::shape_circle){
        if (behavior == 1){
            type_1(test_object);
        }else if (behavior == 2){
            type_2(test_object);
        }else if (behavior == 3){
            type_3(test_object);
        }
    }
}

bool ObjectParticleBall::isIs_alive() const {
    return is_alive;
}

void ObjectParticleBall::setIs_alive(bool is_alive) {
    ObjectParticleBall::is_alive = is_alive;
}

bool ObjectParticleBall::isGive_birth() const {
    return give_birth;
}

void ObjectParticleBall::setGive_birth(bool give_birth) {
    ObjectParticleBall::give_birth = give_birth;
}
