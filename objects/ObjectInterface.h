//
// Created by joar on 11/5/16.
//

#ifndef GAME_OF_RANDOM_OBJECTINTERFACE_H
#define GAME_OF_RANDOM_OBJECTINTERFACE_H


#include <SFML/Graphics.hpp>

enum ShapeType{
    shape_circle
};

class ObjectInterface{

public:

    virtual void draw(sf::RenderWindow &) = 0;
    virtual void process(sf::Time time) = 0;
    virtual void proximityControl(ObjectInterface* test_object) = 0;

    sf::Shape *getShape() const;
    const sf::Vector2f &getSpeed() const;
    const sf::Vector2f &getSize() const;
    const sf::Vector2f &getPosition() const;
    ShapeType getShape_type() const;

    const sf::Vector2f getCenterPosition() const;
    void setShape(sf::Shape *shape);
    void setSpeed(const sf::Vector2f &speed);
    void setSize(const sf::Vector2f &size);

    void setPosition(const sf::Vector2f &position);

protected:
    void setShape_type(ShapeType shape_type);

private:
    ShapeType shape_type;
    sf::Shape* shape;
    sf::Vector2f speed;
    sf::Vector2f size;


};
/*
virtual void setTexture(sf::Texture*);


 */

#endif //GAME_OF_RANDOM_OBJECTINTERFACE_H
