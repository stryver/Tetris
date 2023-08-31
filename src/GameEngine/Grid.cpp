//
// Created by Gaulthier Boggio on 02/08/2023.
//

#include "Grid.h"

Grid::Grid() {
    const int gridSizeX = 10;
    const int gridSizeY = 20;
    const sf::Color defaultColor = sf::Color::White;
    for (int y = 0; y < gridSizeY; ++y) {
        for (int x = 0; x < gridSizeX; ++x) {
            int posX = x;
            int posY = y;
            GridCase.emplace_back(posX, posY);
        }
    }
}

Grid::~Grid() {

}

std::vector<Case> Grid::getGridCase() {
    return this->GridCase;
}

Case Grid::getCase(int x, int y) {
    return this->GridCase[x + y * 10];
}

void Grid::setCase(int x, int y, sf::Color color, bool isEmpty, sf::Color lightColor, sf::Color darkColor) {
    this->GridCase[x + y * 10].setColor(color);
    this->GridCase[x + y * 10].setIsEmpty(isEmpty);
    this->GridCase[x + y * 10].setBorderColor(lightColor, darkColor);
}
