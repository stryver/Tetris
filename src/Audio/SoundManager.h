//
// Created by Gaulthier Boggio on 04/08/2023.
//

#ifndef IA_TETRIS_SOUNDMANAGER_H
#define IA_TETRIS_SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>

class SoundManager {
public:
    SoundManager();
    ~SoundManager();
    void playMusic();
    void stopMusic();
    void playMenuMusic();
    void stopMenuMusic();
    void playHighScore();
    void pauseMusic();
    void playGameOver();
    void playLine();
    void playNextLevel();
    void playNewHighScore();
private:
    sf::Music music;
    sf::Music menuMusic;
    sf::SoundBuffer gameOverBuffer;
    sf::SoundBuffer lineBuffer;
    sf::SoundBuffer nextLevelBuffer;
    sf::SoundBuffer newHighScoreBuffer;
    sf::Sound gameOverSound;
    sf::Sound lineSound;
    sf::Sound nextLevelSound;
    sf::Sound newHighScoreSound;
};


#endif //IA_TETRIS_SOUNDMANAGER_H
