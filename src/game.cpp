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
      sprite_renderer_(width, height) {
  LoadAssets();

  EntityFactory::CreatePaddle(registry_);
  EntityFactory::CreateBlock(registry_, glm::vec2(0.0f), BlockType::RED);
  EntityFactory::CreateBlock(registry_, glm::vec2(128.0f), BlockType::GREEN);
  EntityFactory::CreateBlock(registry_, glm::vec2(256.0f), BlockType::BLUE);
  EntityFactory::CreateBlock(registry_, glm::vec2(0.0f, 128.0f),
                             BlockType::UNBREAKABLE);
}

Game::~Game() { ResourceManager::Clear(); }

void Game::LoadAssets() {
  ResourceManager::LoadShader("sprite", "../assets/shaders/sprite.vs",
                              "../assets/shaders/sprite.fs");

  ResourceManager::LoadTexture("paddle", "../assets/textures/paddle.png");
  ResourceManager::LoadTexture("block", "../assets/textures/block.png");
  ResourceManager::LoadTexture("block_solid",
                               "../assets/textures/block_solid.png");
}

void Game::ProcessInput(float dt) {
  //
}

void Game::Update(float dt) {}

void Game::Render() { sprite_renderer_.Render(registry_); }

void Game::SetKeyPressed(uint key) {
  if (key >= 0 && key < kKeysCount_) {
    keys_[key] = true;
  }
}

void Game::SetKeyReleased(uint key) {
  if (key >= 0 && key < kKeysCount_) {
    keys_[key] = false;
  }
}

bool Game::IsKeyPressed(uint key) {
  if (key >= 0 && key < kKeysCount_) {
    return keys_[key];
  }

  return false;
}
