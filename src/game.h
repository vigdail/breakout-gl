#pragma once

#include <vector>

#include <entt/entt.hpp>

#include "resource_manager.h"
#include "systems/sprite_renderer.h"
#include "systems/input_system.h"
#include "systems/move_system.h"
#include "level.h"

enum GameState {
  GAME_MENU,
  GAME_ACTIVE,
  GAME_WIN,
};

class Game {
 public:
  Game(uint width, uint height);
  ~Game();
  void LoadAssets();
  void ProcessInput(float dt);
  void Update(float dt);
  void Render();
  void SetKeyPressed(uint key);
  void SetKeyReleased(uint key);
  bool IsKeyPressed(uint key);

 private:
  static const uint kKeysCount_ = 1024;
  entt::registry registry_;
  uint width_;
  uint height_;
  GameState state_;
  bool keys_[kKeysCount_];
  std::vector<Level> levels_;

  SpriteRenderer sprite_renderer_;
  InputSystem input_system_;
  MoveSystem move_system_;
};
