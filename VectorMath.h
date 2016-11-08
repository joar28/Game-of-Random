//
// Created by joar on 11/8/16.
//

#ifndef GAME_OF_RANDOM_VECTORMATH_H
#define GAME_OF_RANDOM_VECTORMATH_H


#include <SFML/System/Vector2.hpp>
#include <cmath>


namespace vm {

    template<class T>
    T distance(sf::Vector2f a, sf::Vector2f b) {
        sf::Vector2f tmp = a-b;

        return (T)sqrt((tmp.x*tmp.x + tmp.y*tmp.y));
    }
}

#endif //GAME_OF_RANDOM_VECTORMATH_H
