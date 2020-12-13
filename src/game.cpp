#include "game.h"

#include <glm/glm.hpp>
#include <iostream>
#include <string>

#include "application.h"
#include "resources.h"
#include "components.h"
#include "entity_factory.h"

const uint Game::kKeysCount_;

Game::Game(uint width, uint height)
    : width_(width),
      height_(height),
      state_(GAME_MENU),
      keys_(),
      levels_(),
      sprite_renderer_(width, height),
      input_system_(),
      move_system_() {
  LoadAssets();

  registry_.set<WindowDimensions>(width, height);

  EntityFactory::CreateBackground(registry_);
  EntityFactory::CreatePaddle(registry_);

  levels_[0].Init(registry_);
}

Game::~Game() { ResourceManager::Clear(); }

void Game::LoadAssets() {
  ResourceManager::LoadShader("sprite", "../assets/shaders/sprite.vs",
                              "../assets/shaders/sprite.fs");

  ResourceManager::LoadTexture("paddle", "../assets/textures/paddle.png");
  ResourceManager::LoadTexture("block", "../assets/textures/block.png");
  ResourceManager::LoadTexture("block_solid",
                               "../assets/textures/block_solid.png");
  ResourceManager::LoadTexture("background",
                               "../assets/textures/background.jpg");

  for (int i = 1; i <= 4; i++) {
    std::string s = "../assets/levels/" + std::to_string(i) + ".lvl";
    Level level;
    level.Load(s);
    levels_.push_back(level);
  }
}

void Game::ProcessInput(float dt) { input_system_.Run(registry_, keys_); }

void Game::Update(float dt) { move_system_.Run(registry_, dt); }

void Game::Render() { sprite_renderer_.Render(registry_); }

void Game::SetKeyPressed(uint key) {
  if (key < kKeysCount_) {
    keys_[key] = true;
  }
}

void Game::SetKeyReleased(uint key) {
  if (key < kKeysCount_) {
    keys_[key] = false;
  }
}

bool Game::IsKeyPressed(uint key) {
  if (key < kKeysCount_) {
    return keys_[key];
  }

  return false;
}
