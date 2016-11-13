//
// Created by joar on 11/13/16.
//

#ifndef GAME_OF_RANDOM_OBJECTCLICKABLE_H
#define GAME_OF_RANDOM_OBJECTCLICKABLE_H


#include "ObjectInterface.h"

class ObjectClickable : public ObjectInterface{
public:
    ObjectClickable();
    virtual void checkClick(sf::Event *event) = 0;
};


#endif //GAME_OF_RANDOM_OBJECTCLICKABLE_H
