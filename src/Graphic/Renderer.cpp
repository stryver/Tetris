//
// Created by Gaulthier Boggio on 01/08/2023.
//

#include "Renderer.h"

Renderer::Renderer() {
    this->window.create(sf::VideoMode(1000, 1300), "Tetris");
    this->window.setFramerateLimit(25);
    if (!this->font.loadFromFile("src/Assets/Fonts/Roboto-Black.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    this->tetrisText.setFont(this->font);
    this->tetrisText.setString("TETRIS !");
    this->tetrisText.setCharacterSize(80);
    this->tetrisText.setFillColor(sf::Color::White);
    this->tetrisText.setPosition(200, 500);
    this->tetrisTextBorder.setFont(this->font);
    this->tetrisTextBorder = this->tetrisText;
    this->tetrisTextBorder.setFillColor(sf::Color::Red);
    this->tetrisTextBorder.move(4, 4);
}

Renderer::~Renderer() {

}

sf::RenderWindow &Renderer::getWindow() {
    return this->window;
}

void Renderer::clearScreen() {
    this->window.clear();
}

void Renderer::display() {
    this->window.display();
}

void Renderer::close() {
    this->window.close();
}

void Renderer::drawOverlay() {
    sf::RectangleShape board(sf::Vector2f(this->overlay.getBoardDimension().x, this->overlay.getBoardDimension().y));
    sf::RectangleShape nextTetriminoBorder(sf::Vector2f(this->overlay.getNextTetriminoDimension().x, this->overlay.getNextTetriminoDimension().y));
    board.setFillColor(sf::Color::Transparent);
    nextTetriminoBorder.setFillColor(sf::Color::Transparent);
    board.setOutlineThickness(5);
    nextTetriminoBorder.setOutlineThickness(5);
    board.setOutlineColor(this->overlay.getBoardColor());
    nextTetriminoBorder.setOutlineColor(this->overlay.getBoardColor());
    board.setPosition(50, 50);
    nextTetriminoBorder.setPosition(600, 50);
    this->window.draw(board);
    this->window.draw(nextTetriminoBorder);
}

void Renderer::drawGrid(Grid MainGrid) {
    std::vector<Case> listCase = MainGrid.getGridCase();
    sf::RectangleShape caseShape(sf::Vector2f(50, 50));
    sf::RectangleShape borderCaseShapeTop(sf::Vector2f(50, 5));
    sf::RectangleShape borderCaseShapeBottom(sf::Vector2f(50, 5));
    sf::RectangleShape borderCaseShapeLeft(sf::Vector2f(5, 50));
    sf::RectangleShape borderCaseShapeRight(sf::Vector2f(5, 50));

    for (auto & i : listCase) {
        if (!i.getIsEmpty()) {
            caseShape.setFillColor(i.getColor());
            caseShape.setPosition(i.getPosition().x * 50 + 50, i.getPosition().y * 50 + 50);
            borderCaseShapeTop.setFillColor(i.getBorderLightColor());
            borderCaseShapeBottom.setFillColor(i.getBorderDarkColor());
            borderCaseShapeLeft.setFillColor(i.getBorderLightColor());
            borderCaseShapeRight.setFillColor(i.getBorderDarkColor());
            borderCaseShapeTop.setPosition(i.getPosition().x * 50 + 50, i.getPosition().y * 50 + 50);
            borderCaseShapeBottom.setPosition(i.getPosition().x * 50 + 50, i.getPosition().y * 50 + 50 + 45);
            borderCaseShapeLeft.setPosition(i.getPosition().x * 50 + 50, i.getPosition().y * 50 + 50);
            borderCaseShapeRight.setPosition(i.getPosition().x * 50 + 50 + 45, i.getPosition().y * 50 + 50);
            this->window.draw(caseShape);
            this->window.draw(borderCaseShapeTop);
            this->window.draw(borderCaseShapeBottom);
            this->window.draw(borderCaseShapeLeft);
            this->window.draw(borderCaseShapeRight);
        }
    }
    sf::RectangleShape grid(sf::Vector2f(50, 50));
    grid.setFillColor(sf::Color::Transparent);
    grid.setOutlineThickness(1);
    grid.setOutlineColor(sf::Color::White);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            grid.setPosition(50 + i * 50, 50 + j * 50);
            this->window.draw(grid);
        }
    }
}

void Renderer::drawTetrimino(Tetrimino MainTetrimino) {
    std::vector<std::vector<int>> TetriShape = MainTetrimino.getShape();
    sf::RectangleShape caseShape(sf::Vector2f(50, 50));
    sf::RectangleShape borderCaseShapeTop(sf::Vector2f(50, 5));
    sf::RectangleShape borderCaseShapeBottom(sf::Vector2f(50, 5));
    sf::RectangleShape borderCaseShapeLeft(sf::Vector2f(5, 50));
    sf::RectangleShape borderCaseShapeRight(sf::Vector2f(5, 50));
    borderCaseShapeTop.setFillColor(MainTetrimino.getBorderLightColor());
    borderCaseShapeBottom.setFillColor(MainTetrimino.getBorderDarkColor());
    borderCaseShapeLeft.setFillColor(MainTetrimino.getBorderDarkColor());
    borderCaseShapeRight.setFillColor(MainTetrimino.getBorderLightColor());
    for (int i = 0; i < TetriShape.size(); i++) {
        for (int j = 0; j < TetriShape[i].size(); j++) {
            if (TetriShape[i][j] == 1) {
                caseShape.setFillColor(MainTetrimino.getColor());
                caseShape.setPosition(MainTetrimino.getPosition().x * 50 + j * 50 + 50, MainTetrimino.getPosition().y * 50 + i * 50 + 50);
                borderCaseShapeTop.setPosition(MainTetrimino.getPosition().x * 50 + j * 50 + 50, MainTetrimino.getPosition().y * 50 + i * 50 + 50);
                borderCaseShapeBottom.setPosition(MainTetrimino.getPosition().x * 50 + j * 50 + 50, MainTetrimino.getPosition().y * 50 + i * 50 + 50 + 45);
                borderCaseShapeLeft.setPosition(MainTetrimino.getPosition().x * 50 + j * 50 + 50, MainTetrimino.getPosition().y * 50 + i * 50 + 50);
                borderCaseShapeRight.setPosition(MainTetrimino.getPosition().x * 50 + j * 50 + 50 + 45, MainTetrimino.getPosition().y * 50 + i * 50 + 50);
                this->window.draw(caseShape);
                this->window.draw(borderCaseShapeTop);
                this->window.draw(borderCaseShapeBottom);
                this->window.draw(borderCaseShapeLeft);
                this->window.draw(borderCaseShapeRight);
            }
        }
    }
}

void Renderer::drawNextTetrimino(Tetrimino NextTetrimino) {
    std::vector<std::vector<int>> TetriShape = NextTetrimino.getShape();
    sf::RectangleShape caseShape(sf::Vector2f(50, 50));
    for (int i = 0; i < TetriShape.size(); i++) {
        for (int j = 0; j < TetriShape[i].size(); j++) {
            if (TetriShape[i][j] == 1) {
                caseShape.setFillColor(NextTetrimino.getColor());
                caseShape.setPosition(600 + j * 50 + 50, 50 + i * 50 + 50);
                this->window.draw(caseShape);
            }
        }
    }

}

void Renderer::drawScore(long score, int level, long highScore) {
    scoreText.setFont(this->font);
    scoreText.setString("Score : " + std::to_string(score));
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(600, 400);
    sf::RectangleShape scoreBoard(sf::Vector2f(this->overlay.getScoreDimension().x, this->overlay.getScoreDimension().y));
    scoreBoard.setFillColor(sf::Color::Transparent);
    scoreBoard.setOutlineThickness(5);
    scoreBoard.setOutlineColor(this->overlay.getBoardColor());
    scoreBoard.setPosition(600, 350);
    this->window.draw(scoreBoard);
    this->window.draw(scoreText);
    scoreText.setString("Level : " + std::to_string(level));
    scoreText.setPosition(600, 500);
    this->window.draw(scoreText);
    scoreText.setString("High Score : " + std::to_string(highScore));
    scoreText.setPosition(600, 700);
    this->window.draw(scoreText);
}

void Renderer::drawGameOver() {
    sf::Text gameOverText;
    gameOverText.setFont(this->font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(600, 600);
    this->window.draw(gameOverText);
    gameOverText.setString("Press R to restart");
    gameOverText.setCharacterSize(30);
    gameOverText.setPosition(600, 700);
    this->window.draw(gameOverText);
}

void Renderer::drawProjectedTetrimino(Tetrimino MainTetrimino) {
    std::vector<std::vector<int>> TetriShape = MainTetrimino.getShape();
    sf::RectangleShape caseShape(sf::Vector2f(50, 50));
    caseShape.setFillColor(sf::Color::Transparent);
    caseShape.setOutlineThickness(-5);
    caseShape.setOutlineColor(MainTetrimino.getBorderLightColor());
    for (int i = 0; i < TetriShape.size(); i++) {
        for (int j = 0; j < TetriShape[i].size(); j++) {
            if (TetriShape[i][j] == 1) {
                caseShape.setPosition(MainTetrimino.getPosition().x * 50 + j * 50 + 50, MainTetrimino.getPosition().y * 50 + i * 50 + 50);
                this->window.draw(caseShape);
            }
        }
    }
}

void Renderer::drawTetris(ScoreManager& scoreManager) {
    if (!scoreManager.getFourLines()) {
        tetrisClock.restart();
        return;
    }
    float elapsedSeconds = tetrisClock.getElapsedTime().asSeconds();
    this->window.draw(this->tetrisText);
    this->window.draw(this->tetrisTextBorder);
    if (elapsedSeconds >= 0.5f) {
        tetrisClock.restart();
        scoreManager.resetFourLines();
    }
}

void Renderer::drawProgressBar(int progress) {
    sf::RectangleShape progressBar(sf::Vector2f(200, 30));
    progressBar.setFillColor(sf::Color::Transparent);
    progressBar.setOutlineThickness(5);
    progressBar.setOutlineColor(this->overlay.getBoardColor());
    progressBar.setPosition(625, 600);
    this->window.draw(progressBar);
    sf::RectangleShape progressShape(sf::Vector2f(progress * 2, 30));
    progressShape.setFillColor(sf::Color::Green);
    progressShape.setPosition(625, 600);
    this->window.draw(progressShape);
}

