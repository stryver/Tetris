//
// Created by Gaulthier Boggio on 02/08/2023.
//

#ifndef IA_TETRIS_GRID_H
#define IA_TETRIS_GRID_H

#include "Case.h"
#include <iostream>

class Grid {
public:
    Grid();
    ~Grid();
    std::vector<Case> getGridCase();
    Case getCase(int x, int y);
    void setCase(int x, int y, sf::Color color, bool isEmpty, sf::Color lightColor, sf::Color darkColor);
private:
    std::vector<Case> GridCase;
};


#endif //IA_TETRIS_GRID_H
