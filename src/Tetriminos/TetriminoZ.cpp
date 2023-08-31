//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "TetriminoZ.h"

TetriminoZ::TetriminoZ() {
    this->shapeTop = {{1, 1, 0},
                      {0, 1, 1}
    };

    this->shapeBottom = {{1, 1, 0},
                         {0, 1, 1}};

    this->shapeRight = {{0, 1},
                        {1, 1},
                        {1, 0}};

    this->shapeLeft = {{0, 1},
                       {1, 1},
                       {1, 0}};
    this->color = sf::Color(220,58, 57,255);
    this->borderDarkColor = sf::Color(141,26,17,255);
    this->borderLightColor = sf::Color(255,102,102,255);
}
