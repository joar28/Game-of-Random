/* Copyright
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */


#ifndef STATEINITLOAD_H_
#define STATEINITLOAD_H_

#include <SFML/Graphics/CircleShape.hpp>
#include "StateInterface.h"


class StateInitLoad : public StateInterface{
  public:
    StateInitLoad();
    virtual void Draw(sf::RenderWindow &window) override;
    virtual void Process(sf::Time DeltaTime) override;
    virtual StateSwitcherData * NextState() override;

    virtual void Event(sf::Event *event) override;

    virtual ~StateInitLoad();

private:

    sf::CircleShape Ballen;
    sf::Vector2f Speed;
    sf::Clock Clock;
};

#endif  // STATEINITLOAD_H_
