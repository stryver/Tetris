//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "TetriminoJ.h"

TetriminoJ::TetriminoJ() {
    this->shapeTop = {{1, 0, 0},
                      {1, 1, 1}
    };

    this->shapeBottom = {{1, 1, 1},
                         {0, 0, 1}};

    this->shapeRight = {{1, 1},
                        {1, 0},
                        {1, 0}};

    this->shapeLeft = {{0, 1},
                       {0, 1},
                       {1, 1}};
    this->color = sf::Color(33,89,153,255);
    this->borderDarkColor = sf::Color(0,10,110,255);
    this->borderLightColor = sf::Color(66,122,200,255);

}
