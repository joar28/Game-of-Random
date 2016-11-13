//
// Created by joar on 11/13/16.
//

#ifndef GAME_OF_RANDOM_OBJECTLEFTSIDEBAR_H
#define GAME_OF_RANDOM_OBJECTLEFTSIDEBAR_H


#include "ObjectInterface.h"
#include <list>

class ObjectLeftSideBar : public ObjectInterface{
public:
    ObjectLeftSideBar(int width);
    virtual void draw(sf::RenderWindow &window) override;
    virtual void process(sf::Time time) override;
    virtual void proximityControl(ObjectInterface *test_object) override;
};


#endif //GAME_OF_RANDOM_OBJECTLEFTSIDEBAR_H
