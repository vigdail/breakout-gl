#include "game.h"

#include <glm/glm.hpp>
#include <iostream>

#include "application.h"
#include "entity_factory.h"

const uint Game::kKeysCount_;

Game::Game(uint width, uint height)
    : width_(width),
      height_(height),
      state_(GAME_MENU),
      keys_(),
      sprite_renderer_(width, height),
      levels_() {
  LoadAssets();

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

  Level level;
  level.Load("../assets/levels/level1.txt");
  levels_.push_back(level);
}

void Game::ProcessInput(float dt) {
  //
}

void Game::Update(float dt) {}

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
