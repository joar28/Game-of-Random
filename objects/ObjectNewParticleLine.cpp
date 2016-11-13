//
// Created by joar on 11/12/16.
//

#include "ObjectNewParticleLine.h"
#include "../globals.h"

ObjectNewParticleLine::ObjectNewParticleLine(sf::Vector2f startpos) {
    setShape_type(ObjectInterface::ShapeType::shape_line);

    line[0] = sf::Vertex(startpos, sf::Color::Red);
    line[1] = sf::Vertex(startpos, sf::Color::Red);
}

void ObjectNewParticleLine::draw(sf::RenderWindow &window) {
    window.draw(line, 2, sf::Lines);
}

void ObjectNewParticleLine::process(sf::Time DeltaTime) {
    line[1].position = sf::Vector2f(sf::Mouse::getPosition(*global_game_resources->getWindow()));

}

void ObjectNewParticleLine::proximityControl(ObjectInterface *test_object) {

}


