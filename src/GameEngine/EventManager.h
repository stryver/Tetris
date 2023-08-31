//
// Created by Gaulthier Boggio on 03/08/2023.
//

#ifndef IA_TETRIS_EVENTMANAGER_H
#define IA_TETRIS_EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameEngine.h"

class EventManager {
public:
    EventManager(GameEngine& gameEngine) : gameEngine(gameEngine) {}
    ~EventManager();
    void handleEvents(sf::RenderWindow& window);
    sf::Event getEvent();
private:
    GameEngine& gameEngine;
    sf::Event event;
};


#endif //IA_TETRIS_EVENTMANAGER_H
