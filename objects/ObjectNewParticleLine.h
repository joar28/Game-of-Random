//
// Created by joar on 11/12/16.
//

#ifndef GAME_OF_RANDOM_OBJECTNEWPARTICLELINE_H
#define GAME_OF_RANDOM_OBJECTNEWPARTICLELINE_H


#include "ObjectInterface.h"

class ObjectNewParticleLine : public ObjectInterface{
public:
    /**
     * Constructor for Particle line
     * @param startpos Stratposition for line
     * @return None
     */
    ObjectNewParticleLine(sf::Vector2f startpos);

    virtual void draw(sf::RenderWindow &window) override;

    /**
     * Updates position in last end to line so it follws mouse pointer
     * @param DeltaTime Time since last game tick
     */
    virtual void process(sf::Time DeltaTime) override;

    virtual void proximityControl(ObjectInterface *test_object) override;


private:
    sf::Vertex line[2];
};


#endif //GAME_OF_RANDOM_OBJECTNEWPARTICLELINE_H
