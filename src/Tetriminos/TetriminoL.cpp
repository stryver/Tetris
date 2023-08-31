//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "TetriminoL.h"

TetriminoL::TetriminoL() {
    this->shapeTop = {{1, 1, 1},
                      {1, 0, 0}
                      };

    this->shapeBottom = {{0, 0, 1},
                         {1, 1, 1}};

    this->shapeRight = {{1, 0},
                        {1, 0},
                        {1, 1}};

    this->shapeLeft = {{1, 1},
                        {0, 1},
                        {0, 1}};
    this->color = sf::Color(235,154,62,255);
    this->borderDarkColor = sf::Color(169,90,32,255);
    this->borderLightColor = sf::Color(255,204,102,255);

}
