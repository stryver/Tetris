#include "src/Graphic/Renderer.h"
#include "src/GameEngine/GameEngine.h"
#include "src/GameEngine/EventManager.h"
#include "src/GameEngine/SettingsManager.h"
#include "src/Menu/Menu.h"

void menuLoop(Renderer& renderer, Menu menu) {
    renderer.clearScreen();
    menu.drawBackground();
    menu.drawButtons();
    renderer.display();
}

int main() {
    SettingsManager settingsManager;
    settingsManager.loadSettings();

    Renderer renderer;
    ScoreManager scoreManager(settingsManager);
    GameEngine gameEngine(renderer.getWindow(), scoreManager, settingsManager);
    EventManager eventManager(gameEngine);
    Menu menu(settingsManager, renderer.getWindow(), gameEngine);

    while (renderer.getWindow().isOpen()) {
        eventManager.handleEvents(renderer.getWindow());
        menu.handleEvents(eventManager.getEvent());

        if (gameEngine.getGameState() == GameEngine::MENU) {
            menuLoop(renderer, menu);
            continue;
        }

        if (!gameEngine.getIsGameOver()) {
            gameEngine.updateGravity();
            gameEngine.updateProjectedTetrimino();
            gameEngine.checkCompleteLine();
            gameEngine.checkGameOver();
        }

        renderer.clearScreen();
        renderer.drawOverlay();
        renderer.drawGrid(gameEngine.getGrid());
        renderer.drawTetrimino(gameEngine.getCurrentTetrimino());
        renderer.drawNextTetrimino(gameEngine.getNextTetrimino());

        if (settingsManager.getProjection()) {
            renderer.drawProjectedTetrimino(gameEngine.getProjectedTetrimino());
        }

        renderer.drawScore(scoreManager.getScore(), scoreManager.getLevel(), scoreManager.getHighScore());
        renderer.drawProgressBar(scoreManager.getPercentNextLevel());
        renderer.drawTetris(scoreManager);
        if (gameEngine.getIsGameOver()) {
            renderer.drawGameOver();
        }
        renderer.display();
    }

    return 0;
}