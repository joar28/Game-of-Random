/* Copyright
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef STATES_STATEINTERFACE_H_
#define STATES_STATEINTERFACE_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include "../ResourceLoader.h"


class StateInterface {
public:
    struct StateSwitcherData{
        StateSwitcherData() : next_state_ptr(nullptr), delete_self(false){}
        StateInterface* next_state_ptr;
        bool delete_self;
    };
    StateInterface();

    virtual void Draw(sf::RenderWindow &window) = 0;
    virtual void Process(sf::Time DeltaTime) = 0;
    virtual StateInterface::StateSwitcherData * NextState() = 0;
    virtual void Event(sf::Event *event) = 0;
    virtual ~StateInterface() {}

    void InitData();

protected:
    StateSwitcherData next_state_data;

};



#endif  // STATES_STATEINTERFACE_H_
