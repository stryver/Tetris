//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "TetriminoI.h"

TetriminoI::TetriminoI() {
    this->shapeTop = {{1, 1, 1, 1}};

    this->shapeBottom = {{1, 1, 1 , 1}};

    this->shapeRight = {{1},
                        {1},
                        {1},
                        {1}};

    this->shapeLeft = {{1},
                       {1},
                       {1},
                       {1}};
    this->color = sf::Color(82,171,222,255);
    this->borderDarkColor = sf::Color(49,122,200,255);
    this->borderLightColor = sf::Color(115,192,234,255);
}
