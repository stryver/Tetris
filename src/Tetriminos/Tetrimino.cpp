//
// Created by Gaulthier Boggio on 03/08/2023.
//

#include "Tetrimino.h"

Tetrimino::Tetrimino() {
    this->position = sf::Vector2f(4, 0);
    this->shapeType = TOP;
    this->shapeBottom = {{1, 1, 1},
                         {0, 1, 0}};
    this->shapeTop = {{0, 1, 0},
                      {1, 1, 1}};
    this->shapeRight = {{1, 0, 0},
                        {1, 1, 0},
                        {1, 0, 0}};
    this->shapeLeft = {{0, 1, 0},
                       {1, 1, 0},
                       {0, 1, 0}};

}

Tetrimino::~Tetrimino() {

}

sf::Vector2f Tetrimino::getPosition() {
    return position;
}

sf::Color Tetrimino::getColor() {
    return color;
}

void Tetrimino::setPosition(sf::Vector2f newPos) {
    this->position = newPos;
}

std::vector<std::vector<int>> Tetrimino::getShape() {
    if (this->shapeType == TOP) {
        return this->shapeTop;
    } else if (this->shapeType == BOTTOM) {
        return this->shapeBottom;
    } else if (this->shapeType == LEFT) {
        return this->shapeLeft;
    } else if (this->shapeType == RIGHT) {
        return this->shapeRight;
    }
    return this->shapeTop;
}

void Tetrimino::rotate() {
    if (this->shapeType == TOP) {
        this->shapeType = RIGHT;
    } else if (this->shapeType == BOTTOM) {
        this->shapeType = LEFT;
    } else if (this->shapeType == RIGHT) {
        this->shapeType = BOTTOM;
    } else if (this->shapeType == LEFT) {
        this->shapeType = TOP;
    }
}

int Tetrimino::getTetriminosWidth() {
    int width = this->getShape()[0].size();
    int height = this->getShape().size();
    int tetriWidth = 0;
    for (int i = 0; i < width; i++) {
        bool lineIsEmpty = true;
        for (int j = 0; j < height; j++) {
            if (this->getShape()[j][i] == 1) {
                lineIsEmpty = false;
            }
        }
        if (!lineIsEmpty) {
            tetriWidth++;
        }
    }
    return tetriWidth;
}

int Tetrimino::getTetriminosHeight() {
    int width = this->getShape()[0].size();
    int height = this->getShape().size();
    int tetriHeight = 0;
    for (int i = 0; i < height; i++) {
        bool lineIsEmpty = true;
        for (int j = 0; j < width; j++) {
            if (this->getShape()[i][j] == 1) {
                lineIsEmpty = false;
            }
        }
        if (!lineIsEmpty) {
            tetriHeight++;
        }
    }
    return tetriHeight;
}

std::vector<std::vector<int>> Tetrimino::getNextShape() {
    if (this->shapeType == TOP) {
        return this->shapeRight;
    } else if (this->shapeType == BOTTOM) {
        return this->shapeLeft;
    } else if (this->shapeType == RIGHT) {
        return this->shapeBottom;
    } else if (this->shapeType == LEFT) {
        return this->shapeTop;
    }
}

sf::Color Tetrimino::getBorderDarkColor() {
    return this->borderDarkColor;
}

sf::Color Tetrimino::getBorderLightColor() {
    return this->borderLightColor;
}
