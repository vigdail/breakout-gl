#include <iostream>

#include <glm/glm.hpp>

#include "application.h"
#include "game.h"
#include "components.h"
const uint Game::kKeysCount_;

Game::Game(uint width, uint height)
    : width_(width), height_(height), state_(GAME_MENU), keys_(), sprite_renderer_(width, height)
{
  LoadAssets();

  auto entity = registry_.create();
  registry_.emplace<Transform>(entity, Transform());
  registry_.emplace<Sprite>(entity, ResourceManager::GetTexture("paddle"));
}

Game::~Game()
{
  ResourceManager::Clear();
}

void Game::LoadAssets()
{
  ResourceManager::LoadShader("sprite", "../assets/shaders/sprite.vs", "../assets/shaders/sprite.fs");
  ResourceManager::LoadTexture("paddle", "../assets/textures/paddle.png");
}

void Game::ProcessInput(float dt)
{
  //
}

void Game::Update(float dt)
{
}

void Game::Render()
{
  sprite_renderer_.Render(registry_);
}

void Game::SetKeyPressed(uint key)
{
  if (key >= 0 && key < kKeysCount_)
  {
    keys_[key] = true;
  }
}

void Game::SetKeyReleased(uint key)
{
  if (key >= 0 && key < kKeysCount_)
  {
    keys_[key] = false;
  }
}

bool Game::IsKeyPressed(uint key)
{
  if (key >= 0 && key < kKeysCount_)
  {
    return keys_[key];
  }

  return false;
}