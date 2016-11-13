//
// Created by joar on 11/5/16.
//

#ifndef GAME_OF_RANDOM_OBJECTPARTICLEBALL_H
#define GAME_OF_RANDOM_OBJECTPARTICLEBALL_H


#include "ObjectInterface.h"

class ObjectParticleBall : public ObjectInterface{
public:

    /**
     * Constructor for particle ball
     * @param position Start position of particle ball
     * @param radius Size of particle ball
     * @param type Integer to choose behavior type of particle
     * @return void
     */
    ObjectParticleBall(sf::Vector2f position, float radius, int type);


    virtual void proximityControl(ObjectInterface *test_object) override;
    virtual void draw(sf::RenderWindow &window) override;
    virtual void process(sf::Time DeltaTime) override;

public:
    /**
     * Returns radius of particel object
     * @return Radius
     */
    float getRadius() const;

    /**
     * Set radius of particel object
     * @param radius Radius
     */
    void setRadius(float radius);

private:
    /**
     * Proximity behavior type 1
     * Will make a swarm
     * @param test_object Object to priximity test
     */
    void type_1(ObjectInterface *test_object);

    /**
     * Proximity behavior type 2
     * Will make a swarm
     * @param test_object Object to priximity test
     */
    void type_2(ObjectInterface *test_object);

    /// Contains behavior type number
    int behavior;

};


#endif //GAME_OF_RANDOM_OBJECTPARTICLEBALL_H
