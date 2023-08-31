//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "TetriminoT.h"

TetriminoT::TetriminoT() {
    this->shapeTop = {{0, 1, 0},
                      {1, 1, 1}
    };

    this->shapeBottom = {{1, 1, 1},
                         {0, 1, 0}};

    this->shapeRight = {{1, 0},
                        {1, 1},
                        {1, 0}};

    this->shapeLeft = {{0, 1},
                       {1, 1},
                       {0, 1}};
    this->color = sf::Color(135,50,136,255);
    this->borderDarkColor = sf::Color(92,19,98,255);
    this->borderLightColor = sf::Color(165,82,167,255);

}
