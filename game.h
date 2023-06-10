#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include"game_level.h"

// Represents the current state of the game - there are three states in total
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
    GameState State;
    bool Keys[1024];
    unsigned int Width, Height;
    //data of levels
    std::vector<GameLevel> Levels;
    //current level
    unsigned int Level; 

    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (to load all shaders, textures, levels)
    void Init();

    // game loop
    void ProcessInput(float dt); //input is from the keys array
    void Update(float dt); //updation of gameplay moments
    void Render();

    void DoCollisions();

    // reset
    void ResetLevel();
    void ResetPlayer();
};

#endif