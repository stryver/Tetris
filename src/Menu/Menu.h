//
// Created by Gaulthier Boggio on 24/08/2023.
//

#ifndef IA_TETRIS_MENU_H
#define IA_TETRIS_MENU_H

#include "../GameEngine/SettingsManager.h"
#include "../GameEngine/GameEngine.h"
#include "../Components/Button.h"
#include "../Components/Slider.h"

class Menu {
public:
    Menu(SettingsManager& settingsManager, sf::RenderWindow& window, GameEngine& gameEngine);
    ~Menu();
    void drawButtons();
    void drawBackground();
    void handleEvents(const sf::Event& event);
private:
    void drawSettings();
    void updateSettings();
private:
    GameEngine& gameEngine;
    SettingsManager& settingsManager;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RenderWindow& window;
    bool settingsOpen;
private:
    Button btNewGame;
    Button btSettings;
    Button btExit;
    Button btAI;
private:
    sf::Text title;
    sf::Font font;
    Slider sliderMusic;
    Slider sliderSound;
    Button btBack;
    Button btSave;
};


#endif //IA_TETRIS_MENU_H
