//
// Created by joar on 11/13/16.
//

#ifndef GAME_OF_RANDOM_OBJECTLEFTSIDEBAR_H
#define GAME_OF_RANDOM_OBJECTLEFTSIDEBAR_H


#include "ObjectInterface.h"
#include <list>

class ObjectLeftSideBar : public ObjectInterface{
public:
    /**
     * Constructor for side bar
     * @param width Set width of left sidebar
     * @return None
     */
    ObjectLeftSideBar(int width);

    virtual ~ObjectLeftSideBar();

    virtual void draw(sf::RenderWindow &window) override;
    virtual void process(sf::Time DeltaTime) override;
    virtual void proximityControl(ObjectInterface *test_object) override;
};


#endif //GAME_OF_RANDOM_OBJECTLEFTSIDEBAR_H
