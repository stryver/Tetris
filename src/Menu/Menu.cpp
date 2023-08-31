//
// Created by Gaulthier Boggio on 24/08/2023.
//

#include "Menu.h"

Menu::Menu(SettingsManager& settingsManager, sf::RenderWindow& window, GameEngine& gameEngine) : settingsManager(settingsManager),
window(window), gameEngine(gameEngine),
btNewGame(sf::Vector2f(100, 100), sf::Vector2f(800, 200), "New Game", 60),
btSettings(sf::Vector2f(100, 400), sf::Vector2f(800, 200), "Settings", 60),
btExit(sf::Vector2f(100, 700), sf::Vector2f(800, 200), "Exit", 60),
btAI(sf::Vector2f(100, 1000), sf::Vector2f(800, 200), "AI", 60),
btBack(sf::Vector2f(100, 1000), sf::Vector2f(300, 60), "Back", 40),
btSave(sf::Vector2f(500, 1000), sf::Vector2f(300, 60), "Save", 40),
sliderMusic(this->settingsManager.getVolumeMusic(), 0, 100, 5, "Music", sf::Vector2f(500, 50), sf::Vector2f(250, 300)),
sliderSound(this->settingsManager.getVolumeSound(), 0, 100, 5, "Sound", sf::Vector2f(500, 50), sf::Vector2f(250, 500))
{
    btNewGame.onClick([&]() {
        gameEngine.setGameState(GameEngine::GameState::PLAYING);
    });
    btExit.onClick([&]() {
        window.close();
    });
    btSettings.onClick([&]() {
        settingsOpen = true;
    });
    btBack.onClick([&]() {
        settingsOpen = false;
    });
    if (!backgroundTexture.loadFromFile("src/Assets/Images/backgroundMenu.jpeg")) {
        std::cout << "Error loading background texture" << std::endl;
    }
    this->settingsOpen = false;
    this->font.loadFromFile("src/Assets/Fonts/Roboto-Black.ttf");
    this->title.setFont(font);
    this->title.setString("Settings");
    this->title.setCharacterSize(100);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1000.0f / backgroundSprite.getLocalBounds().width, 1300.0f / backgroundSprite.getLocalBounds().height);
}

Menu::~Menu() {}

void Menu::drawSettings() {
    window.draw(title);
    sliderMusic.draw(window);
    sliderSound.draw(window);
    btBack.draw(window);
    btSave.draw(window);
}

void Menu::updateSettings() {
    settingsManager.setVolumeMusic(sliderMusic.getValue());
    settingsManager.setVolumeSound(sliderSound.getValue());
    settingsManager.saveSettings();
}

void Menu::handleEvents(const sf::Event& event) {
    btNewGame.handleEvent(event, window);
    btSettings.handleEvent(event, window);
    btExit.handleEvent(event, window);
    btAI.handleEvent(event, window);
    btBack.handleEvent(event, window);
    btSave.handleEvent(event, window);
    sliderMusic.handleEvent(event, window);
    sliderSound.handleEvent(event, window);
}

void Menu::drawButtons() {
    if (settingsOpen) {
        drawSettings();
        updateSettings();
        return;
    }
    btNewGame.draw(window);
    btSettings.draw(window);
    btExit.draw(window);
    btAI.draw(window);
}

void Menu::drawBackground() {
    window.draw(backgroundSprite);
}



