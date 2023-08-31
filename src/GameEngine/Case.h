//
// Created by Gaulthier Boggio on 02/08/2023.
//

#ifndef IA_TETRIS_CASE_H
#define IA_TETRIS_CASE_H

#include <SFML/Graphics.hpp>

class Case {
public:
    Case(int x, int y);
    ~Case();
    sf::Vector2f getPosition();
    sf::Color getColor();
    sf::Color getBorderDarkColor();
    sf::Color getBorderLightColor();
    bool getIsEmpty();
    void setColor(sf::Color color);
    void setBorderColor(sf::Color lightColor, sf::Color darkColor);
    void setIsEmpty(bool isEmpty);
private:
    sf::Vector2f position;
    sf::Color color;
    sf::Color borderDarkColor;
    sf::Color borderLightColor;
    bool isEmpty;
};


#endif //IA_TETRIS_CASE_H
