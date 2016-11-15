//

#include "ObjectInterface.h"



//
// Created by joar on 11/5/16.
ObjectInterface::ObjectInterface(
        ObjectInterface::ShapeType shape_type,
        ObjectInterface::DerivedClassType derivedClass,
        bool clickable)
        :
        shape_type(shape_type),
        derivedClass(derivedClass),
        clickable(clickable)
{

}

const sf::Vector2f ObjectInterface::getCenterPosition() const {
    sf::Vector2f pos(-1.f, -1.f);

    switch (shape_type){
        case shape_not_set:break;
        case shape_circle:{
            float radius = ((sf::CircleShape*)shape)->getRadius();
            pos = getPosition() - sf::Vector2f(radius, radius);
        }break;
        case shape_line: pos = shape->getPosition()+sf::Vector2f(getSize().x/2, getSize().x/2); break;
        case shape_rectangle: break; //todo implement rectangle position
    }

    return pos;
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

void ObjectInterface::setShape_type(ObjectInterface::ShapeType shape_type) {
    ObjectInterface::shape_type = shape_type;
}

ObjectInterface::ShapeType ObjectInterface::getShape_type() const {
    return shape_type;
}





ObjectInterface::~ObjectInterface() {
    delete shape;
}





bool ObjectInterface::IsClickable() const {
    return clickable;
}

void ObjectInterface::setClickable(bool isClickable) {
    ObjectInterface::clickable = isClickable;
}

bool ObjectInterface::isMarked_for_delete() const {
    return marked_for_delete;
}

void ObjectInterface::setMarked_for_delete(bool marked_for_delete) {
    ObjectInterface::marked_for_delete = marked_for_delete;
}

ObjectInterface::DerivedClassType ObjectInterface::getDerivedClass() const {
    return derivedClass;
}
