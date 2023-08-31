//
// Created by Gaulthier Boggio on 02/08/2023.
//

#ifndef IA_TETRIS_GAMEENGINE_H
#define IA_TETRIS_GAMEENGINE_H

#include "Grid.h"
#include "../Tetriminos/Tetrimino.h"
#include "../Tetriminos/TetriminoI.h"
#include "../Tetriminos/TetriminoO.h"
#include "../Tetriminos/TetriminoT.h"
#include "../Tetriminos/TetriminoL.h"
#include "../Tetriminos/TetriminoJ.h"
#include "../Tetriminos/TetriminoZ.h"
#include "../Tetriminos/TetriminoS.h"
#include "../Audio/SoundManager.h"
#include "ScoreManager.h"
#include "../Tools.h"
#include "SettingsManager.h"

class GameEngine {
private:
    enum MoveType {
        DOWN,
        LEFT,
        RIGHT,
        ROTATE
    };
public:
    enum GameState {
        PLAYING,
        GAMEOVER,
        PAUSE,
        MENU
    };
public:
    GameEngine(sf::RenderWindow& window, ScoreManager& scoreManager, SettingsManager& settingsManager);
    ~GameEngine();
    Grid getGrid();
    void updateGravity();
    Tetrimino getCurrentTetrimino();
    Tetrimino getNextTetrimino();
    Tetrimino getProjectedTetrimino();
    void checkCompleteLine();
    void newGame();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate();
    void fixTetriminosInGrid();
    bool getIsGameOver();
    void checkGameOver();
    void updateProjectedTetrimino();
    void setGameState(GameState gameState);
    GameState getGameState();
    void quitGame();
private:
    bool isNextMovePossible(int x, int y, MoveType moveType);
    bool simulateProjectedTetrimino(int x, int y, MoveType moveType);
    void moveDownLine(int y);
    Tetrimino spawnTetri();
    bool rotateIsPossible();
private:
    Tools tools;
    sf::RenderWindow& window;
    Grid grid;
    Tetrimino CurrentTetrimino;
    Tetrimino NextTetrimino;
    Tetrimino projectedTetrimino;
    sf::Clock gravityClock;
    SoundManager soundManager;
    ScoreManager& scoreManager;
    bool isGameOver;
    GameState gameState;
    SettingsManager& settingsManager;
};


#endif //IA_TETRIS_GAMEENGINE_H
