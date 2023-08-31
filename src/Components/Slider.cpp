//
// Created by Gaulthier Boggio on 25/08/2023.
//

#include "Slider.h"

Slider::Slider(int value, int minValue, int maxValue, int step, std::string text, sf::Vector2f size, sf::Vector2f position) : size(size),
position(position),
btLeft(sf::Vector2f(position.x - 70, position.y), sf::Vector2f(50, 50), "-", 30),
btRight(sf::Vector2f(position.x + size.x + 20, position.y), sf::Vector2f(50, 50), "+", 30)
{
    this->value = static_cast<float>(value);
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->step = step;
    if (!this->font.loadFromFile("src/Assets/Fonts/Roboto-Black.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(40);
    this->text.setPosition(position.x + this->size.x / 2 - this->text.getGlobalBounds().width, position.y + size.y - (this->text.getGlobalBounds().height + 80));
    this->text.setFillColor(sf::Color::White);
    this->sliderBar.setSize(sf::Vector2f((this->value * this->size.x) / 100, this->size.y));
    this->sliderBar.setFillColor(sf::Color::White);
    this->sliderBar.setPosition(this->position);
    this->borderSliderBar.setSize(this->size);
    this->borderSliderBar.setFillColor(sf::Color::Transparent);
    this->borderSliderBar.setOutlineThickness(4);
    this->borderSliderBar.setOutlineColor(sf::Color::Blue);
    this->borderSliderBar.setPosition(this->position);
}

Slider::~Slider() {

}

void Slider::draw(sf::RenderWindow &window) {
    btLeft.draw(window);
    btRight.draw(window);
    window.draw(this->text);
    window.draw(this->sliderBar);
    window.draw(this->borderSliderBar);
}

void Slider::handleEvent(const sf::Event &event, const sf::RenderWindow &window) {
    btLeft.handleEvent(event, window);
    btRight.handleEvent(event, window);
}

int Slider::getValue() {
    return static_cast<int>(this->value);
}

