#ifndef MAINGAME_HPP
#define MAINGAME_HPP
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <format>

enum class GameState {PLAY, EXIT};

class MainGame {

public:
    MainGame();
    ~MainGame();

    void run();

private:
    void initSystems();
    void gameLoop();
    void processInput();

    SDL_Window* _window;

    int _screenWidth;
    int _screenHeight;
    GameState _gameState;

};

#endif //MAINGAME_HPP
