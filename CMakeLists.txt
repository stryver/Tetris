cmake_minimum_required(VERSION 3.23)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)
set(SFML_INCLUDE_DIR ". /SFML/include")
set(SFML_LIBRARY_DIR ". /SFML/build/lib")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(IA_Tetris
        main.cpp
        src/Graphic/Renderer.cpp
        src/Graphic/Overlay.cpp
        src/GameEngine/Grid.cpp
        src/GameEngine/GameEngine.cpp
        src/GameEngine/EventManager.cpp
        src/GameEngine/Case.cpp
        src/GameEngine/ScoreManager.cpp
        src/GameEngine/SettingsManager.cpp
        src/Tetriminos/Tetrimino.cpp
        src/Tetriminos/TetriminoI.cpp
        src/Tetriminos/TetriminoO.cpp
        src/Tetriminos/TetriminoT.cpp
        src/Tetriminos/TetriminoL.cpp
        src/Tetriminos/TetriminoJ.cpp
        src/Tetriminos/TetriminoZ.cpp
        src/Tetriminos/TetriminoS.cpp
        src/Menu/Menu.cpp
        src/Components/Button.cpp
        src/Components/Slider.cpp
        src/Audio/SoundManager.cpp
        src/Tools.cpp
        )

target_link_libraries (IA_Tetris sfml-graphics sfml-window sfml-system sfml-audio)