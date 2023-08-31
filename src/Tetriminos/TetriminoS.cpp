//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "TetriminoS.h"

TetriminoS::TetriminoS() {
    this->shapeTop = {{0, 1, 1},
                      {1, 1, 0}
    };

    this->shapeBottom = {{0, 1, 1},
                         {1, 1, 0}};

    this->shapeRight = {{1, 0},
                        {1, 1},
                        {0, 1}};

    this->shapeLeft = {{1, 0},
                       {1, 1},
                       {0, 1}};
    this->color = sf::Color(106,180,85,255);
    this->borderDarkColor = sf::Color(68,150,42,255);
    this->borderLightColor = sf::Color(132,204,110,255);

}
