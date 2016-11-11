//
// Created by joar on 11/8/16.
//

#ifndef GAME_OF_RANDOM_VECTORMATH_H
#define GAME_OF_RANDOM_VECTORMATH_H


#include <SFML/System/Vector2.hpp>
#include <cmath>


namespace vm {

    template<class T>
    T distance(sf::Vector2<T> a, sf::Vector2<T> b) {
        sf::Vector2<T> tmp = a-b;
        return (T)sqrt((tmp.x*tmp.x + tmp.y*tmp.y));
    }

    template<class T>
    T speed(sf::Vector2<T> speed){
        return (T)sqrt((speed.x*speed.x + speed.y*speed.y));
    }
}

#endif //GAME_OF_RANDOM_VECTORMATH_H
