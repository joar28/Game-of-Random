//
// Created by joar on 11/12/16.
//

#ifndef GAME_OF_RANDOM_OBJECTNEWPARTICLELINE_H
#define GAME_OF_RANDOM_OBJECTNEWPARTICLELINE_H


#include "ObjectInterface.h"

class ObjectNewParticleLine : public ObjectInterface{
public:
    ObjectNewParticleLine(sf::Vector2f startpos);

    virtual void draw(sf::RenderWindow &window) override;

    virtual void process(sf::Time time) override;

    virtual void proximityControl(ObjectInterface *test_object) override;

    virtual ~ObjectNewParticleLine();

private:
    sf::Vertex line[2];
};


#endif //GAME_OF_RANDOM_OBJECTNEWPARTICLELINE_H
