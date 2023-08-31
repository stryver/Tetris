//
// Created by Gaulthier Boggio on 20/08/2023.
//

#include "SettingsManager.h"

SettingsManager::SettingsManager() {
    this->volumeMusic = 100;
    this->volumeSound = 100;
    this->highScore = 0;
    this->projection = false;
}

SettingsManager::~SettingsManager() {

}

void SettingsManager::loadSettings() {
    std::ifstream inputFile("config.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening settings file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t delimiterPos = line.find(":");
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            if (key == "music") {
                this->volumeMusic = std::stoi(line.substr(delimiterPos + 1));
            }
            if (key == "effect") {
                this->volumeSound = std::stoi(line.substr(delimiterPos + 1));
            }
            if (key == "highscore") {
                this->highScore = std::stoi(line.substr(delimiterPos + 1));
            }
            if (key == "projection") {
                this->projection = line.substr(delimiterPos + 1) == "true";
            }
        }
    }
}

bool SettingsManager::getProjection() {
    return this->projection;
}

int SettingsManager::getVolumeMusic() {
    return this->volumeMusic;
}

long SettingsManager::getHighScore() {
    return this->highScore;
}

int SettingsManager::getVolumeSound() {
    return this->volumeSound;
}

void SettingsManager::setVolumeMusic(int volume) {
    this->volumeMusic = volume;
}

void SettingsManager::setVolumeSound(int volume) {
    this->volumeSound = volume;
}

void SettingsManager::setHighScore(long score) {
    this->highScore = score;
}

void SettingsManager::setProjection(bool projection) {
    this->projection = projection;
}

void SettingsManager::saveSettings() {
    std::cout << "Saving settings" << highScore << std::endl;
    std::ofstream outputFile("config.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening settings file" << std::endl;
        return;
    }
    outputFile << "music:" << this->volumeMusic << std::endl;
    outputFile << "effect:" << this->volumeSound << std::endl;
    outputFile << "highscore:" << this->highScore << std::endl;
    outputFile << "projection:" << (this->projection ? "true" : "false") << std::endl;
    outputFile.close();
}
