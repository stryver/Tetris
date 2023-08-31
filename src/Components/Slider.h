//
// Created by Gaulthier Boggio on 25/08/2023.
//

#ifndef IA_TETRIS_SLIDER_H
#define IA_TETRIS_SLIDER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class Slider {
public:
    Slider(int value, int minValue, int maxValue, int step, std::string text, sf::Vector2f size, sf::Vector2f position);
    ~Slider();
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    int getValue();
private:
    sf::RectangleShape sliderBar;
    sf::RectangleShape borderSliderBar;
    sf::Text text;
    sf::Font font;
    sf::Vector2f size;
    sf::Vector2f position;
    float value;
    Button btLeft;
    Button btRight;
    int minValue;
    int maxValue;
    int step;
};


#endif //IA_TETRIS_SLIDER_H
