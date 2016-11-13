//
// Created by joar on 11/13/16.
//

#ifndef GAME_OF_RANDOM_OBJECTBUTTON_H
#define GAME_OF_RANDOM_OBJECTBUTTON_H


#include <functional>
#include "ObjectClickable.h"

class ObjectButton : public ObjectClickable{
public:
    /**
     * Button constructor.
     * @param position Position of button
     * @param text_s Text to be displayed on button
     * @param cb Pointer to callback function/method
     * @return None
     */
    ObjectButton(const sf::Vector2f &position, std::string text_s, std::function<int()> cb);

    virtual void draw(sf::RenderWindow &window) override;

    virtual void process(sf::Time time) override;

    virtual void proximityControl(ObjectInterface *test_object) override;

    virtual void checkClick(sf::Event *event) override;

private:
    std::string text_string;
    sf::Text text;
    sf::Vector2f position;
    sf::RectangleShape background;
    std::function<int()> callback;
};


#endif //GAME_OF_RANDOM_OBJECTBUTTON_H
