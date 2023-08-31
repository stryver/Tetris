//
// Created by Gaulthier Boggio on 02/08/2023.
//

#include "Case.h"

Case::Case(int x, int y) {
    this->position = sf::Vector2f(x, y);
    this->color = sf::Color::Transparent;
    this->borderDarkColor = sf::Color::Transparent;
    this->borderLightColor = sf::Color::Transparent;
    this->isEmpty = true;
}

Case::~Case() {}

sf::Vector2f Case::getPosition() {
    return this->position;
}

sf::Color Case::getColor() {
    return this->color;
}

bool Case::getIsEmpty() {
    return this->isEmpty;
}

void Case::setColor(sf::Color color) {
    this->color = color;
}

void Case::setIsEmpty(bool isEmpty) {
    this->isEmpty = isEmpty;
}

sf::Color Case::getBorderDarkColor() {
    return this->borderDarkColor;
}

sf::Color Case::getBorderLightColor() {
    return this->borderLightColor;
}

void Case::setBorderColor(sf::Color lightColor, sf::Color darkColor) {
    this->borderLightColor = lightColor;
    this->borderDarkColor = darkColor;
}
