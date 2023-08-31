//
// Created by Gaulthier Boggio on 24/08/2023.
//

#ifndef IA_TETRIS_BUTTON_H
#define IA_TETRIS_BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

class Button {
private:
    enum ButtonState {
        IDLE,
        HOVER,
        CLICKED
    };
public:
    Button(sf::Vector2f position, sf::Vector2f size, std::string text, int fontSize);
    ~Button();
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void onClick(std::function<void()> action);
private:
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color borderColorIdle;
    sf::Color borderColorHover;
    std::function<void()> onClickAction;
    ButtonState state;
    bool wasClicked;
};


#endif //IA_TETRIS_BUTTON_H
