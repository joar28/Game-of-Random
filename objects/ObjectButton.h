//
// Created by joar on 11/13/16.
//

#ifndef GAME_OF_RANDOM_OBJECTBUTTON_H
#define GAME_OF_RANDOM_OBJECTBUTTON_H


#include <functional>
#include "ObjectClickable.h"

class ObjectButton : public ObjectClickable{
public:
    ObjectButton(const sf::Vector2f &position, std::string text_string, std::function<int()> cb);

    virtual void draw(sf::RenderWindow &window) override;

    virtual void process(sf::Time time) override;

    virtual void proximityControl(ObjectInterface *test_object) override;

    virtual void checkClick(sf::Event *event) override;

private:
    sf::Text text;
    sf::Vector2f position;
    sf::RectangleShape background;
    std::function<void()> callback;
};


#endif //GAME_OF_RANDOM_OBJECTBUTTON_H
