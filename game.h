#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include"game_level.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Game holds all game - related state and functionality. 

class Game
{
public:
    // game state
    GameState               State;
    bool                    Keys[1024];
    unsigned int            Width, Height;
    std::vector<GameLevel> Levels;
    unsigned int Level;

    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (load all shaders/textures/levels)
    void Init();

    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

#endif