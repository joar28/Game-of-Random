//
// Created by joar on 11/13/16.
//

#include "ObjectLeftSideBar.h"
#include "../globals.h"

ObjectLeftSideBar::ObjectLeftSideBar(int width) : ObjectInterface(ShapeType::shape_rectangle, DerivedClassType::object_left_side_bar, false)
{

    sf::RectangleShape* rs = new sf::RectangleShape(sf::Vector2f(width, global_game_resources->getWindow()->getSize().y));
    rs->setFillColor(sf::Color(85,85,85));
    setShape(rs);
}

void ObjectLeftSideBar::draw(sf::RenderWindow &window) {
    window.draw(*getShape());
}
void ObjectLeftSideBar::process(sf::Time DeltaTime) {}

void ObjectLeftSideBar::proximityControl(ObjectInterface *test_object) {}

ObjectLeftSideBar::~ObjectLeftSideBar() {
    delete((sf::RectangleShape*)getShape());
}


