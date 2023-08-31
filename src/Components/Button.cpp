//
// Created by Gaulthier Boggio on 24/08/2023.
//

#include "Button.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text, int fontSize)
{
    if (buffer.loadFromFile("src/Assets/Sound/Hover.flac")) {
        sound.setBuffer(buffer);
    } else {
        std::cout << "Error loading line sound" << std::endl;
    }
    sound.setVolume(100);
    this->wasClicked = false;
    this->state = IDLE;
    this->position = position;
    this->size = size;
    this->idleColor = sf::Color(34, 34, 34, 255);
    this->hoverColor = sf::Color(100, 100, 100, 255);
    this->borderColorIdle = sf::Color(255, 255, 255, 255);
    this->borderColorHover = sf::Color(20, 20, 20, 255);
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(idleColor);
    shape.setOutlineThickness(5);
    shape.setOutlineColor(borderColorIdle);
    if (!this->font.loadFromFile("src/Assets/Fonts/Roboto-Black.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(fontSize);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(position.x + size.x / 2 - this->text.getGlobalBounds().width / 2, position.y + size.y / 2 - this->text.getGlobalBounds().height / 2);
}

Button::~Button() {

}

void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseMoved) {
        if (shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            this->state = HOVER;
            sound.play();
        } else {
            this->state = IDLE;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && onClickAction && !wasClicked) {
            onClickAction();
            wasClicked = true;
        }
    } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        wasClicked = false;
    }
}

void Button::onClick(std::function<void()> action) {
    onClickAction = action;
}

void Button::draw(sf::RenderWindow &window) {
    if (state == HOVER) {
        shape.setFillColor(hoverColor);
        shape.setOutlineColor(borderColorHover);
    } else if (state == IDLE) {
        shape.setFillColor(idleColor);
        shape.setOutlineColor(borderColorIdle);
    }
    window.draw(shape);
    window.draw(text);
}

