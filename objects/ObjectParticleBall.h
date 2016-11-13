//
// Created by joar on 11/5/16.
//

#ifndef GAME_OF_RANDOM_OBJECTPARTICLEBALL_H
#define GAME_OF_RANDOM_OBJECTPARTICLEBALL_H


#include "ObjectInterface.h"

class ObjectParticleBall : public ObjectInterface{
public:

    /**
     * @param position Startposition of particle ball
     * @param radius Size of particle ball
     * @param type Integer to choose behavior type of particle
     * @return void
     */
    ObjectParticleBall(sf::Vector2f position, float radius, int type);


    virtual void proximityControl(ObjectInterface *test_object) override;
    virtual void draw(sf::RenderWindow &window) override;
    virtual void process(sf::Time DeltaTime) override;

public:
    float getRadius() const;

    void setRadius(float radius);

private:
    void type_1(ObjectInterface *test_object);
    void type_2(ObjectInterface *test_object);
    int behavior;

};


#endif //GAME_OF_RANDOM_OBJECTPARTICLEBALL_H
