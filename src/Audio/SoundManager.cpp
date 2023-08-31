//
// Created by Gaulthier Boggio on 04/08/2023.
//

#include "SoundManager.h"

SoundManager::SoundManager() {
    if (!music.openFromFile("src/Assets/Sound/A-Type.flac")) {
        std::cout << "Error loading music" << std::endl;
    }
    if (!menuMusic.openFromFile("src/Assets/Sound/Menu.flac")) {
        std::cout << "Error loading menu music" << std::endl;
    }
    music.setLoop(true);
    music.setVolume(50);
    menuMusic.setLoop(true);
    menuMusic.setVolume(25);
    if (lineBuffer.loadFromFile("src/Assets/Sound/ClearLine.flac")) {
        lineSound.setBuffer(lineBuffer);
    } else {
        std::cout << "Error loading line sound" << std::endl;
    }
    if (nextLevelBuffer.loadFromFile("src/Assets/Sound/NextLevel.flac")) {
        nextLevelSound.setBuffer(nextLevelBuffer);
    } else {
        std::cout << "Error loading next level sound" << std::endl;
    }
    if (newHighScoreBuffer.loadFromFile("src/Assets/Sound/HighScore.flac")) {
        newHighScoreSound.setBuffer(newHighScoreBuffer);
    } else {
        std::cout << "Error loading new high score sound" << std::endl;
    }
}

SoundManager::~SoundManager() {

}

void SoundManager::playMusic() {
    music.play();
}

void SoundManager::stopMusic() {
    music.stop();
}

void SoundManager::pauseMusic() {
    music.pause();
}

void SoundManager::playGameOver() {
    if (gameOverBuffer.loadFromFile("src/Assets/Sound/GameOver.flac")) {
        gameOverSound.setBuffer(gameOverBuffer);
        gameOverSound.play();
    } else {
        std::cout << "Error loading game over sound" << std::endl;
    }
}

void SoundManager::playLine() {
    lineSound.play();
}

void SoundManager::playNextLevel() {
    nextLevelSound.play();
}

void SoundManager::playMenuMusic() {
    menuMusic.play();
}

void SoundManager::stopMenuMusic() {
    menuMusic.stop();
}

void SoundManager::playNewHighScore() {

}

void SoundManager::playHighScore() {
    newHighScoreSound.play();
}
