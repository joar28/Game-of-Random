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

    /**
     * Types of shape
     */
    enum ShapeType{
        shape_not_set = -1, ///< Default shape if shapetype is not updated (Should not happen)
        shape_circle = 0,   ///< If shape is circle
        shape_line,         ///< If shape is line
        shape_rectangle,    ///< If shape is rectangle
    };

/**
     * Types of derived class
     */
    enum DerivedClassType{
        object_type_not_set = -1,   ///< If objectType is not set (Should not happen)
        object_button       = 0,    ///< If objectType is button
        object_left_side_bar,       ///< If objectType is left side bar
        object_new_particle_line,   ///< If objectType is new particle line
        object_particle_ball,       ///< If objectType is \ref ObjectParticleBall
    };

    ObjectInterface(ShapeType shape_type, DerivedClassType derivedClass, bool clickable);

    /**
     * Draw self function.
     * @param window address to the window to draw self on.
     */
    virtual void draw(sf::RenderWindow &) = 0;

    /**
     * Executes game tick logic
     * @param DeltaTime Time since last game tick
     */
    virtual void process(sf::Time DeltaTime) = 0;

    /**
     * This method checks for how close to a object it is, and executes
     * behavioral type logic.
     * @param test_object pointer to external object of proximity control.
     */
    virtual void proximityControl(ObjectInterface* test_object) = 0;

    /**
     *
     * @return pointer to drawable shape
     */
    sf::Shape *getShape() const;

    /**
     * @return Current speed
     */
    const sf::Vector2f &getSpeed() const;

    /**
     * Returns size of object
     * @return size
     */
    const sf::Vector2f &getSize() const;

    /**
     * Get position of object
     * @return position coordinate
     */
    const sf::Vector2f &getPosition() const;

    /**
     * Get shape type
     * @return ShapeType enumerator
     */
    ObjectInterface::ShapeType getShape_type() const;

    /**
     * Calculates centerposition if possible
     * @return Position coordinate
     */
    const sf::Vector2f getCenterPosition() const;

    /**
     * Setter for drawable shape
     * @param shape shape pointer
     */
    void setShape(sf::Shape *shape);

    /**
     * Set object speed-
     * @param speed speed
     */
    void setSpeed(const sf::Vector2f &speed);

    /**
     * Set size of object
     * @param size size
     */
    void setSize(const sf::Vector2f &size);

    /**
     * Set object position
     * @param position position
     */
    void setPosition(const sf::Vector2f &position);

    /**
     * Returns if object is clickable
     * @return Clickable
     */
    bool IsClickable() const;

    /**
     * Set clickable status
     * @param isClickable is it clickable?
     */
    void setClickable(bool isClickable);

    /**
     * Will return which derived class type
     * @return DerivedClassType enum
     */
    DerivedClassType getDerivedClass() const;


protected:
    /**
     * Set shape type
     * @param shape_type shape type
     */
    void setShape_type(ObjectInterface::ShapeType shape_type);


    /**
     * Object interface deconstructor
     */
    ~ObjectInterface();
private:
    /// Contains shape type
    ShapeType shape_type = shape_not_set;

    /// Contains shape type
    DerivedClassType derivedClass = object_type_not_set;

    /// Pointer to drawable shape
    sf::Shape* shape = nullptr;

    /// Vector speed
    sf::Vector2f speed;

    sf::Vector2f size;

    /// True if object should be clickable
    bool clickable = false;
    bool marked_for_delete = false;
public:
    bool isMarked_for_delete() const;

    void setMarked_for_delete(bool marked_for_delete);

};

#endif //GAME_OF_RANDOM_OBJECTINTERFACE_H
