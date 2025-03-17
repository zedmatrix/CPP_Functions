#include "MainGame.hpp"

MainGame::MainGame () {
    _window = nullptr;
    _screenWidth = 640;
    _screenHeight = 480;
    _gameState = GameState::PLAY;
}

MainGame::~MainGame () {

}

void MainGame::run() {
    initSystems();
    gameLoop();

}
void MainGame::initSystems() {

    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow("Demo Init",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               _screenWidth,
                               _screenHeight,
                               SDL_WINDOW_OPENGL);


}
void MainGame::gameLoop() {

    while (_gameState != GameState::EXIT) {
        processInput();
    }

}
void MainGame::processInput() {

    SDL_Event _event;

    while (SDL_PollEvent(&_event)) {
        switch (_event.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                std::cout << std::format("Mouse({},{})\n", _event.motion.y, _event.motion.x);
                break;
            case SDL_MOUSEWHEEL:
                std::cout << std::format("Mouse({},{})\n", _event.wheel.y, _event.wheel.x);
                break;
            default:
                SDL_Log("Unhandled Event!");
                break;
        }
    }
}
