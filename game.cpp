#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"


//State data
SpriteRenderer* Renderer;

//constructor
Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("default.vert", "default.frag", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    // load textures
    ResourceManager::LoadTexture("background.jpg", false, "background");
    ResourceManager::LoadTexture("ball.png", true, "ball");
    ResourceManager::LoadTexture("block.png", false, "block");
    ResourceManager::LoadTexture("block_solid.png", false, "block_solid");

    // load levels
    GameLevel one; one.Load("one.lvl", this->Width, this->Height / 2);
    GameLevel two; two.Load("two.lvl", this->Width, this->Height / 2);
    GameLevel three; three.Load("three.lvl", this->Width, this->Height / 2);
    GameLevel four; four.Load("four.lvl", this->Width, this->Height / 2);

    this->Levels.push_back(one); 
    this->Levels.push_back(two);
    this->Levels.push_back(three);
    this->Levels.push_back(four);
    this->Level = 0;
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    if (this->State == GAME_ACTIVE)
    {
        // draw background
        Renderer->DrawSprite(ResourceManager::GetTexture("background"),
            glm::vec2(0.0f, 0.0f), glm::vec2(this->Width, this->Height), 0.0f
        );
        // draw level
        this->Levels[this->Level].Draw(*Renderer);
    }

    /*Renderer->DrawSprite(ResourceManager::GetTexture("ball"), glm::vec2(400.0f, 500.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));*/
}