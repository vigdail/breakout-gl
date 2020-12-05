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
  void loadAssets();
  void processInput(float dt);
  void update(float dt);
  void render();

private:
  entt::registry registry_;
  uint width_;
  uint height_;
  GameState state_;
  bool keys_[1024];
};