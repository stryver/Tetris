//
// Created by Gaulthier Boggio on 02/08/2023.
//

#include "GameEngine.h"

//PRIVATE
void GameEngine::moveDownLine(int y) {
    for (int i = y; i > 0; i--) {
        for (int j = 0; j < 10; j++) {
            grid.setCase(j, i, grid.getCase(j, i - 1).getColor(), grid.getCase(j, i - 1).getIsEmpty(), grid.getCase(j, i - 1).getBorderLightColor(), grid.getCase(j, i - 1).getBorderDarkColor());
        }
    }
}

Tetrimino GameEngine::spawnTetri() {
    int randTetri = Tools::getRandomNumber(1, 7);
    if (randTetri == 1) {
        return TetriminoZ();
    }
    if (randTetri == 2) {
        return TetriminoO();
    }
    if (randTetri == 3) {
        return TetriminoT();
    }
    if (randTetri == 4) {
        return TetriminoL();
    }
    if (randTetri == 5) {
        return TetriminoJ();
    }
    if (randTetri == 6) {
        return TetriminoI();
    }
    if (randTetri == 7) {
        return TetriminoS();
    }
}

bool GameEngine::rotateIsPossible() {
    Tetrimino tetrimino = CurrentTetrimino;
    tetrimino.rotate();
    sf::Vector2f position = tetrimino.getPosition();
    std::vector<std::vector<int>> shape = tetrimino.getShape();
    for (int x = 0; x < tetrimino.getShape().size(); x++) {
        for (int y = 0; y < tetrimino.getShape()[x].size(); y++) {
            if (shape[x][y] == 1) {
                if (position.x + y < 0 || position.x + y > 9 || position.y + x < 0 || position.y + x > 19) {
                    return false;
                }
                if (!grid.getCase(position.x + y, position.y + x).getIsEmpty()) {
                    return false;
                }
            }
        }
    }
    return true;
}

//PUBLIC
GameEngine::GameEngine(sf::RenderWindow& window, ScoreManager& scoreManager1, SettingsManager& settingsManager) : window(window), scoreManager(scoreManager1), settingsManager(settingsManager) {
    this->CurrentTetrimino = this->spawnTetri();
    this->NextTetrimino = this->spawnTetri();
    this->projectedTetrimino = this->CurrentTetrimino;
    this->isGameOver = false;
    this->gameState = MENU;
    this->soundManager.playMenuMusic();
}

GameEngine::~GameEngine() {

}

//PUBLIC

Grid GameEngine::getGrid() {
    return grid;
}

Tetrimino GameEngine::getCurrentTetrimino() {
    return CurrentTetrimino;
}

Tetrimino GameEngine::getNextTetrimino() {
    return NextTetrimino;
}

Tetrimino GameEngine::getProjectedTetrimino() {
    return this->projectedTetrimino;
}

bool GameEngine::getIsGameOver() {
    return isGameOver;
}

void GameEngine::updateGravity() {
    float elapsedSeconds = gravityClock.getElapsedTime().asSeconds();
    if (elapsedSeconds >= 0.5f - (scoreManager.getLevel() * 0.05f)) {
        gravityClock.restart();
        this->moveDown();
    }
}

//Move

void GameEngine::moveDown() {
    if (this->isNextMovePossible(this->CurrentTetrimino.getPosition().x, this->CurrentTetrimino.getPosition().y + 1, MoveType::DOWN)) {
        this->CurrentTetrimino.setPosition(sf::Vector2f(this->CurrentTetrimino.getPosition().x, this->CurrentTetrimino.getPosition().y + 1));
    } else {
        this->fixTetriminosInGrid();
    }
}

void GameEngine::rotate() {
    if (this->rotateIsPossible()) {
        this->CurrentTetrimino.rotate();
    }
}

void GameEngine::moveLeft() {
    if (this->isNextMovePossible(this->CurrentTetrimino.getPosition().x - 1, this->CurrentTetrimino.getPosition().y, MoveType::LEFT)) {
        this->CurrentTetrimino.setPosition(sf::Vector2f(this->CurrentTetrimino.getPosition().x - 1, this->CurrentTetrimino.getPosition().y));
    }
}

void GameEngine::moveRight() {
    if (this->isNextMovePossible(this->CurrentTetrimino.getPosition().x + 1, this->CurrentTetrimino.getPosition().y, MoveType::RIGHT)) {
        this->CurrentTetrimino.setPosition(sf::Vector2f(this->CurrentTetrimino.getPosition().x + 1, this->CurrentTetrimino.getPosition().y));
    }
}

//Game
bool GameEngine::isNextMovePossible(int x, int y, MoveType moveType) {
    sf::Vector2f position = CurrentTetrimino.getPosition();
    std::vector<std::vector<int>> shape = CurrentTetrimino.getShape();
    CurrentTetrimino.getTetriminosWidth();
    if (moveType == DOWN) {
        for (int i = 0; i < CurrentTetrimino.getShape().size(); i++) {
            for (int j = 0; j < CurrentTetrimino.getShape()[i].size(); j++) {
                if (shape[i][j] == 1) {
                    if (y > 20 - CurrentTetrimino.getTetriminosHeight()) {
                        return false;
                    }
                }
            }
        }
    }
    if (moveType == DOWN) {
        for (int i = 0; i < CurrentTetrimino.getShape().size(); i++) {
            for (int j = 0; j < CurrentTetrimino.getShape()[i].size(); j++) {
                if (shape[i][j] == 1) {
                    if (!grid.getCase(position.x + j, position.y + i + 1).getIsEmpty()) {
                        return false;
                    }
                }
            }
        }
    }
    if (moveType == LEFT) {
        for (int i = 0; i < CurrentTetrimino.getShape().size(); i++) {
            for (int j = 0; j < CurrentTetrimino.getShape()[i].size(); j++) {
                if (shape[i][j] == 1) {
                     if (x < 0) {
                        return false;
                    }
                     if (!grid.getCase(position.x + j - 1, position.y + i).getIsEmpty()) {
                         return false;
                     }
                }
            }
        }
    }
    if (moveType == RIGHT) {
        for (int i = CurrentTetrimino.getShape().size() - 1; i >= 0; i--) {
            for (int j = 0; j < CurrentTetrimino.getShape()[i].size(); j++) {
                if (shape[i][j] == 1) {
                    if (x > 10 - CurrentTetrimino.getTetriminosWidth()) {
                        return false;
                    }
                    if (!grid.getCase(position.x + j + 1, position.y + i).getIsEmpty()) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool GameEngine::simulateProjectedTetrimino(int x, int y, GameEngine::MoveType moveType) {
    sf::Vector2f position = projectedTetrimino.getPosition();
    std::vector<std::vector<int>> shape = projectedTetrimino.getShape();
    projectedTetrimino.getTetriminosWidth();
    if (moveType == DOWN) {
        for (int i = 0; i < projectedTetrimino.getShape().size(); i++) {
            for (int j = 0; j < projectedTetrimino.getShape()[i].size(); j++) {
                if (shape[i][j] == 1) {
                    if (y > 20 - projectedTetrimino.getTetriminosHeight()) {
                        return false;
                    }
                }
            }
        }
    }
    if (moveType == DOWN) {
        for (int i = 0; i < projectedTetrimino.getShape().size(); i++) {
            for (int j = 0; j < projectedTetrimino.getShape()[i].size(); j++) {
                if (shape[i][j] == 1) {
                    if (!grid.getCase(position.x + j, position.y + i + 1).getIsEmpty()) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


void GameEngine::fixTetriminosInGrid() {
    sf::Vector2f position = CurrentTetrimino.getPosition();
    std::vector<std::vector<int>> shape = CurrentTetrimino.getShape();
    for (int x = 0; x < CurrentTetrimino.getShape().size(); x++) {
        for (int y = 0; y < CurrentTetrimino.getShape()[x].size(); y++) {
            if (shape[x][y] == 1) {
                grid.setCase(position.x + y, position.y + x, CurrentTetrimino.getColor(), false, CurrentTetrimino.getBorderLightColor(), CurrentTetrimino.getBorderDarkColor());
            }
        }
    }
    CurrentTetrimino = NextTetrimino;
    NextTetrimino = this->spawnTetri();
}

void GameEngine::checkCompleteLine() {
    int nbLineComplete = 0;
    for (int y = 0; y < 20; y++) {
        bool completeLine = true;
        for (int x = 0; x < 10; x++) {
            if (grid.getCase(x, y).getIsEmpty()) {
                completeLine = false;
            }
        }
        if (completeLine) {
            nbLineComplete++;
            for (int x = 0; x < 10; x++) {
                grid.setCase(x, y, sf::Color::Transparent, true, sf::Color::Transparent, sf::Color::Transparent);
            }
            this->moveDownLine(y);
            this->soundManager.playLine();
        }
    }
    this->scoreManager.addScore(nbLineComplete, &this->soundManager);
}

void GameEngine::checkGameOver() {
    for (int x = 0; x < 10; x++) {
        if (!grid.getCase(x, 0).getIsEmpty()) {
            isGameOver = true;
            this->soundManager.stopMusic();
            this->soundManager.playGameOver();
            this->settingsManager.setHighScore(this->scoreManager.getScore());
            this->settingsManager.saveSettings();
        }
    }
}

void GameEngine::newGame() {
    grid = Grid();
    CurrentTetrimino = this->spawnTetri();
    NextTetrimino = this->spawnTetri();
    isGameOver = false;
    scoreManager.resetScore();
    this->soundManager.playMusic();
}

void GameEngine::updateProjectedTetrimino() {
    this->projectedTetrimino = this->CurrentTetrimino;
    while (this->simulateProjectedTetrimino(this->projectedTetrimino.getPosition().x, this->projectedTetrimino.getPosition().y + 1, MoveType::DOWN)) {
        this->projectedTetrimino.setPosition(
                sf::Vector2f(this->projectedTetrimino.getPosition().x, this->projectedTetrimino.getPosition().y + 1));
    }
}

void GameEngine::setGameState(GameEngine::GameState gameState) {
    this->gameState = gameState;
    if (gameState == GameState::PLAYING) {
        this->soundManager.stopMenuMusic();
        this->soundManager.playMusic();
    }
}

GameEngine::GameState GameEngine::getGameState() {
    return this->gameState;
}

void GameEngine::quitGame() {
    this->window.close();
}



