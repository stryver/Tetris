//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "TetriminoO.h"

TetriminoO::TetriminoO() {
    this->shapeTop = {{1, 1},
                      {1, 1}};
    this->shapeBottom = {{1, 1},
                      {1, 1}};
    this->shapeLeft = {{1, 1},
                      {1, 1}};
    this->shapeRight = {{1, 1},
                      {1, 1}};
    this->color = sf::Color(249,225,76,255);
    this->borderDarkColor = sf::Color(230,172,59,255);
    this->borderLightColor = sf::Color(255,204,102,255);

}
