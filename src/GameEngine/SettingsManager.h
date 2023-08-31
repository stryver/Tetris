//
// Created by Gaulthier Boggio on 20/08/2023.
//

#ifndef IA_TETRIS_SETTINGSMANAGER_H
#define IA_TETRIS_SETTINGSMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class SettingsManager {
public:
    SettingsManager();
    ~SettingsManager();
    void loadSettings();
    bool getProjection();
    long getHighScore();
    int getVolumeMusic();
    int getVolumeSound();
    void setVolumeMusic(int volume);
    void setVolumeSound(int volume);
    void setHighScore(long score);
    void setProjection(bool projection);
    void saveSettings();
private:
    int volumeMusic;
    int volumeSound;
    long highScore;
    bool projection;
};


#endif //IA_TETRIS_SETTINGSMANAGER_H
