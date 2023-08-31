//
// Created by Gaulthier Boggio on 01/08/2023.
//

#include "Overlay.h"

Overlay::Overlay() {
    this->boardDimension = sf::Vector2f(500, 1000);
    this->BoardColor = sf::Color::White;
    this->nextTetriminoDimension = sf::Vector2f(250, 250);
    this->scoreDimension = sf::Vector2f(250, 500);
}

Overlay::~Overlay() {}


sf::Color Overlay::getBoardColor() {
    return this->BoardColor;
}

sf::Vector2f Overlay::getBoardDimension() {
    return this->boardDimension;
}

sf::Vector2f Overlay::getNextTetriminoDimension() {
    return this->nextTetriminoDimension;
}

sf::Vector2f Overlay::getScoreDimension() {
    return this->scoreDimension;
}
