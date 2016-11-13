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

    /**
     * Types of shape
     */
    enum ShapeType{
        shape_not_set = -1,
        shape_circle = 0,
        shape_line,
        shape_left_side_bar,
        shape_button,
    };

    /**
     * Draw self function.
     * @param window address to the window to draw self on.
     */
    virtual void draw(sf::RenderWindow &) = 0;

    /**
     * Executes game tick logic
     * @param DeltaTime
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

protected:
    /**
     * Set shape type
     * @param shape_type shape type
     */
    void setShape_type(ObjectInterface::ShapeType shape_type);

private:
    /// Contains shape type
    ShapeType shape_type = shape_not_set;

    /// Pointer to drawable shape
    sf::Shape* shape = nullptr;

    /// Vector speed
    sf::Vector2f speed;

    sf::Vector2f size;

    /// True if object should be clickable
    bool clickable = false;

};

#endif //GAME_OF_RANDOM_OBJECTINTERFACE_H
