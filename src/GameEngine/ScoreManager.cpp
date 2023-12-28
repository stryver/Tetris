//
// Created by Gaulthier Boggio on 07/08/2023.
//

#include "ScoreManager.h"

ScoreManager::ScoreManager(SettingsManager& settingsManager) : settingsManager(settingsManager) {
    this->score = 0;
    this->level = 1;
    this->fourLines = false;
    this->prevLevelScore = 1;
    this->nextLevelScore = 1000;
    this->highScore = settingsManager.getHighScore();
    this->newHighScore = false;
}

ScoreManager::~ScoreManager() {

}

void ScoreManager::addScore(int line, SoundManager *soundManager) {
    if (line == 1) {
        this->score = this->score + 80 * (this->level + 1);
    } else if (line == 2) {
        this->score = this->score + 100 * (this->level + 1);
    } else if (line == 3) {
        this->score = this->score + 300 * (this->level + 1);
    } else if (line == 4) {
        this->score = this->score + 1200 * (this->level + 1);
        this->fourLines = true;
    }
    if(this->score >= this->nextLevelScore) {
        soundManager->playNextLevel();
        this->level++;
        this->prevLevelScore = this->nextLevelScore;
        this->nextLevelScore = this->level * 1000;
    }
    this->nbLine = this->nbLine + line;
    std::cout << "Score: " << this->score << std::endl;
    std::cout << "HighScore : " << this->highScore << std::endl;
    if (this->score > this->highScore) {
        if (!this->newHighScore) {
            this->newHighScore = true;
            soundManager->playHighScore();
        }
        this->highScore = this->score;
    }
}

long ScoreManager::getScore() {
    return this->score;
}

void ScoreManager::resetScore() {
    this->score = 0;
    this->score = 0;
    this->level = 1;
    this->fourLines = false;
    this->prevLevelScore = 1;
    this->nextLevelScore = 1000;
}

int ScoreManager::getLevel() {
    return this->level;
}

bool ScoreManager::getFourLines() {
    return this->fourLines;
}

void ScoreManager::resetFourLines() {
    this->fourLines = false;
}

int ScoreManager::getPercentNextLevel() {
    int min = this->prevLevelScore;
    int max = this->nextLevelScore;
    int score = this->score;
    return (score - min) * 100 / (max - min);
}

int ScoreManager::getNextLevelScore() {
    return this->nextLevelScore;
}

int ScoreManager::getHighScore() {
    return this->highScore;
}
