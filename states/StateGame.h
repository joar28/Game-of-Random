//
// Created by joar on 11/5/16.
//

#ifndef GAME_OF_RANDOM_STATEGAME_H
#define GAME_OF_RANDOM_STATEGAME_H


#include "StateInterface.h"
#include "../objects/ObjectInterface.h"
#include <list>
#include <functional>

class StateGame : public StateInterface{
public:
    StateGame();

    virtual void Draw(sf::RenderWindow &window) override;

    virtual void Process(sf::Time DeltaTime) override;

    virtual StateSwitcherData NextState() override;

    virtual void Event(sf::Event *event) override;

private:
    std::list<ObjectInterface*> ObjectList;

    void MouseButtonPressed(sf::Event *event);

    void MouseButtonReleased(sf::Event *event);

    sf::Vector2f mouse_last_pressed;
    bool first_mouse_release;

    void KeyPressed(sf::Event *event);

    void KeyReleased(sf::Event *event);

    void add_button(std::string text, std::function<int()> cb);

    int callback_type_particle();

    int next_particle_type = 0;
    int number_of_particle_types = 0;
};


#endif //GAME_OF_RANDOM_STATEGAME_H
