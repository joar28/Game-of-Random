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
    /**
     * Contains pointer to next state, have to contain itself if state is
     * not going ti be swiched
     */
    struct StateSwitcherData{
        StateSwitcherData() : next_state_ptr(nullptr), delete_self(false){}
        /// Pointer to next state.
        StateInterface* next_state_ptr;

        /**
         * True if state shoud be deleted after swich. False if it should ttill be on the stack
         */
        bool delete_self;
    };

    /**
     * StateInterface constructors, sets next state pointer
     * in \ref StateInterface::StateSwitcherData to self
     *
     * @return None
     */
    StateInterface();

    /**
     * This method is called when the state machine should draw window
     * @param window window address to draw on
     */
    virtual void Draw(sf::RenderWindow &window) = 0;

    /**
     * Process method, takes time difference since last "game tick" to update position
     * and other stuff
     * @param DeltaTime
     */
    virtual void Process(sf::Time DeltaTime) = 0;

    /**
     * Asks the state which state should be run next, if it returnes itself
     * it does not change state.
     * @return  pointer to StateSwitcherData struct
     */
    virtual StateInterface::StateSwitcherData NextState() = 0;

    /**
     * Takes in all events from SFML
     * @param event sf::event pointer
     */
    virtual void Event(sf::Event *event) = 0;

    /**
     * State deconstructor
     */
    virtual ~StateInterface() {}

    void InitData();

protected:
    /// Holds information of next state.
    StateSwitcherData next_state_data;

};



#endif  // STATES_STATEINTERFACE_H_
