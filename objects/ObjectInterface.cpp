//
// Created by joar on 11/5/16.
//

#include "ObjectInterface.h"

const sf::Vector2f ObjectInterface::getCenterPosition() const {
    if(shape_type == shape_circle){
        return shape->getPosition()+sf::Vector2f(((sf::CircleShape*)shape)->getRadius(), ((sf::CircleShape*)shape)->getRadius());
    }
    return shape->getPosition()+getSize();
}

const sf::Vector2f &ObjectInterface::getSpeed() const {
    return speed;
}

void ObjectInterface::setSpeed(const sf::Vector2f &speed) {
    ObjectInterface::speed = speed;
}

const sf::Vector2f &ObjectInterface::getSize() const {

    return size;
}

void ObjectInterface::setSize(const sf::Vector2f &size) {
    ObjectInterface::size = size;
}

sf::Shape *ObjectInterface::getShape() const {
    return shape;
}

void ObjectInterface::setShape(sf::Shape *shape) {
    ObjectInterface::shape = shape;
}

const sf::Vector2f &ObjectInterface::getPosition() const {
    return shape->getPosition();
}

void ObjectInterface::setPosition(const sf::Vector2f &position) {
    shape->setPosition(position);
}

void ObjectInterface::setShape_type(ShapeType shape_type) {
    ObjectInterface::shape_type = shape_type;
}

ShapeType ObjectInterface::getShape_type() const {
    return shape_type;
}
