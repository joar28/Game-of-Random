//
// Created by joar on 11/5/16.
//

#ifndef GAME_OF_RANDOM_OBJECTPARTICLEBALL_H
#define GAME_OF_RANDOM_OBJECTPARTICLEBALL_H


#include "ObjectInterface.h"

class ObjectParticleBall : public ObjectInterface{
public:
    ObjectParticleBall(sf::Vector2f position, float radius);

    virtual void proximityControl(ObjectInterface *test_object) override;

    virtual void draw(sf::RenderWindow &window) override;
    virtual void process(sf::Time time) override;

public:
    float getRadius() const;

    void setRadius(float radius);

private:

};


#endif //GAME_OF_RANDOM_OBJECTPARTICLEBALL_H
