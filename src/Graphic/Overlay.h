//
// Created by Gaulthier Boggio on 01/08/2023.
//

#ifndef IA_TETRIS_OVERLAY_H
#define IA_TETRIS_OVERLAY_H

#include "SFML/Graphics.hpp"

class Overlay {
public:
    Overlay();
    ~Overlay();
    sf::Vector2f getBoardDimension();
    sf::Vector2f getNextTetriminoDimension();
    sf::Vector2f getScoreDimension();
    sf::Color getBoardColor();
private:
    sf::Vector2f boardDimension;
    sf::Vector2f nextTetriminoDimension;
    sf::Vector2f scoreDimension;
    sf::Color BoardColor;
};


#endif //IA_TETRIS_OVERLAY_H
