#pragma once

#include <entt/entt.hpp>

enum GameState
{
    GAME_MENU,
    GAME_ACTIVE,
    GAME_WIN,
};

class Game
{
public:
    Game(uint width, uint height);
    ~Game();
    void loadAssets();
    void processInput(float dt);
    void update(float dt);
    void render();

private:
    entt::registry m_Registry;
    uint m_Width;
    uint m_Height;
    GameState m_State;
    bool m_Keys[1024];
};