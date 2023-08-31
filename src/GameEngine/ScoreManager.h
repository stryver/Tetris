//
// Created by Gaulthier Boggio on 07/08/2023.
//

#ifndef IA_TETRIS_SCOREMANAGER_H
#define IA_TETRIS_SCOREMANAGER_H

#include <iostream>
#include "../Audio/SoundManager.h"
#include "SettingsManager.h"

class ScoreManager {
public:
    ScoreManager(SettingsManager& settingsManager);
    ~ScoreManager();
    void addScore(int line, SoundManager *soundManager);
    long getScore();
    int getLevel();
    int getHighScore();
    bool getFourLines();
    void resetFourLines();
    int getPercentNextLevel();
    int getNextLevelScore();
    void resetScore();
private:
    long highScore;
    int level;
    long score;
    bool fourLines;
    bool newHighScore;
    long nextLevelScore;
    long prevLevelScore;
    int nbLine;
    SettingsManager& settingsManager;
};


#endif //IA_TETRIS_SCOREMANAGER_H
