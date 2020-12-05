#pragma once

#include <entt/entt.hpp>

#include "shader.h"

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
  void LoadAssets();
  void ProcessInput(float dt);
  void Update(float dt);
  void Render();

private:
  entt::registry registry_;
  uint width_;
  uint height_;
  GameState state_;
  bool keys_[1024];
};