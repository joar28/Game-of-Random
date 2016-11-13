//
// Created by joar on 11/5/16.
//

#ifndef GAME_OF_RANDOM_OBJECTINTERFACE_H
#define GAME_OF_RANDOM_OBJECTINTERFACE_H


#include <SFML/Graphics.hpp>

/*
virtual void setTexture(sf::Texture*);


 */


class ObjectInterface{
public:
    ~ObjectInterface();
    enum ShapeType{
        shape_not_set = -1,
        shape_circle = 0,
        shape_line,
        shape_left_side_bar,
        shape_button,
    };

    virtual void draw(sf::RenderWindow &) = 0;
    virtual void process(sf::Time time) = 0;
    virtual void proximityControl(ObjectInterface* test_object) = 0;

    sf::Shape *getShape() const;
    const sf::Vector2f &getSpeed() const;
    const sf::Vector2f &getSize() const;
    const sf::Vector2f &getPosition() const;
    ObjectInterface::ShapeType getShape_type() const;

    const sf::Vector2f getCenterPosition() const;
    void setShape(sf::Shape *shape);
    void setSpeed(const sf::Vector2f &speed);
    void setSize(const sf::Vector2f &size);

    void setPosition(const sf::Vector2f &position);

    bool IsClickable() const;
    void setClickable(bool isClickable);

protected:
    void setShape_type(ObjectInterface::ShapeType shape_type);

private:
    ShapeType shape_type = shape_not_set;
    sf::Shape* shape = nullptr;
    sf::Vector2f speed;
    sf::Vector2f size;
    bool clickable = false;

};

#endif //GAME_OF_RANDOM_OBJECTINTERFACE_H
