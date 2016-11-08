//
// Created by joar on 11/5/16.
//

#ifndef GAME_OF_RANDOM_STATEGAME_H
#define GAME_OF_RANDOM_STATEGAME_H


#include "StateInterface.h"
#include "../objects/ObjectInterface.h"
#include <list>

class StateGame : public StateInterface{
public:
    StateGame();

    virtual void Draw(sf::RenderWindow &window) override;

    virtual void Process(sf::Time DeltaTime) override;

    virtual StateSwitcherData *NextState() override;

    virtual void Event(sf::Event *event) override;

private:
    std::list<ObjectInterface*> ObjectList;
};


#endif //GAME_OF_RANDOM_STATEGAME_H
