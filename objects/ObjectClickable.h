//
// Created by joar on 11/13/16.
//

#ifndef GAME_OF_RANDOM_OBJECTCLICKABLE_H
#define GAME_OF_RANDOM_OBJECTCLICKABLE_H


#include "ObjectInterface.h"

class ObjectClickable : public ObjectInterface{
public:
    /**
     * Constructor for clickable object
     * @return None
     */
    //ShapeType shape_type, DerivedClassType derivedClass, bool clickable
    ObjectClickable(ShapeType shape_type, DerivedClassType derivedClass, bool clickable);

    /**
     * This method checks if mouse pointer is hovering over itself,
     * and handles if it has been clicked.
     * @param event contains click event
     */
    virtual void checkClick(sf::Event *event) = 0;
};


#endif //GAME_OF_RANDOM_OBJECTCLICKABLE_H
