//
// Created by Gaulthier Boggio on 03/08/2023.
//

#ifndef IA_TETRIS_TETRIMINO_H
#define IA_TETRIS_TETRIMINO_H

#include <SFML/Graphics.hpp>
#include "../Tools.h"

class Tetrimino {
public:
    Tetrimino();
    ~Tetrimino();
    sf::Vector2f getPosition();
    sf::Color getColor();
    sf::Color getBorderDarkColor();
    sf::Color getBorderLightColor();
    void setPosition(sf::Vector2f newPos);
    std::vector<std::vector<int>> getShape();
    std::vector<std::vector<int>> getNextShape();
    void rotate();
    int getTetriminosWidth();
    int getTetriminosHeight();
private:
    enum ShapeType {
        TOP,
        BOTTOM,
        RIGHT,
        LEFT
    };
private:
    ShapeType shapeType;
    sf::Vector2f position;
    Tools tools;
protected:
    sf::Color color;
    sf::Color borderDarkColor;
    sf::Color borderLightColor;
    std::vector<std::vector<int>> shapeTop;
    std::vector<std::vector<int>> shapeBottom;
    std::vector<std::vector<int>> shapeRight;
    std::vector<std::vector<int>> shapeLeft;
};


#endif //IA_TETRIS_TETRIMINO_H
