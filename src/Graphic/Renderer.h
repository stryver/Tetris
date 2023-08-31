//
// Created by Gaulthier Boggio on 01/08/2023.
//

#ifndef IA_TETRIS_RENDERER_H
#define IA_TETRIS_RENDERER_H

#include "Overlay.h"
#include <SFML/Graphics.hpp>
#include "../GameEngine/Grid.h"
#include "../Tetriminos/Tetrimino.h"
#include "../GameEngine/ScoreManager.h"
class Renderer {
public:
    Renderer();
    ~Renderer();
    sf::RenderWindow& getWindow();
    void clearScreen();
    void display();
    void close();
    void drawGameOver();
    void drawOverlay();
    void drawGrid(Grid MainGrid);
    void drawTetrimino(Tetrimino MainTetrimino);
    void drawProjectedTetrimino(Tetrimino MainTetrimino);
    void drawNextTetrimino(Tetrimino NextTetrimino);
    void drawScore(long score, int level, long highScore);
    void drawTetris(ScoreManager& scoreManager);
    void drawProgressBar(int progress);
private:
    sf::RenderWindow window;
    sf::Font font;
    Overlay overlay;
    sf::Clock tetrisClock;
    sf::Text tetrisText;
    sf::Text tetrisTextBorder;
    sf::Text scoreText;
    sf::RectangleShape progressBarBorder;
    sf::RectangleShape progressBarContent;
};


#endif //IA_TETRIS_RENDERER_H
