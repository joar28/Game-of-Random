//
// Created by joar on 11/4/16.
//

#ifndef STATEMAINMENU_H_
#define STATEMAINMENU_H_

#include "StateInterface.h"
class StateMainMenu : public StateInterface{
  public:
    StateMainMenu();

    virtual void Draw(sf::RenderWindow &window) override;
    virtual void Process(sf::Time DeltaTime) override;
    virtual StateInterface::StateSwitcherData NextState() override;

    virtual void Event(sf::Event *event) override;


private:
    sf::Text text_heading;
    sf::CircleShape Ballen;
    std::map<sf::Text*, std::string> menuText;
    void addMenuText(std::string text, std::string actionString);
    void menuChoiceAction(std::string actionString);
};

#endif  // STATEMAINMENU_H_
