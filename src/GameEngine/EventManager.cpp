//
// Created by Gaulthier Boggio on 03/08/2023.
//

#include "EventManager.h"

EventManager::~EventManager() {

}

void EventManager::handleEvents(sf::RenderWindow& window) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (!this->gameEngine.getIsGameOver()) {
                if (event.key.code == sf::Keyboard::Space) {
                    gameEngine.rotate();
                }
                if (event.key.code == sf::Keyboard::Left) {
                    gameEngine.moveLeft();
                }
                if (event.key.code == sf::Keyboard::Right) {
                    gameEngine.moveRight();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    gameEngine.moveDown();
                }
            }
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::R) {
                gameEngine.newGame();
            }
        }
    }
}

sf::Event EventManager::getEvent() {
    return event;
}
