#include <iostream>

#include <glm/glm.hpp>

#include "application.h"
#include "game.h"

const uint Game::kKeysCount_;

Game::Game(uint width, uint height)
    : width_(width), height_(height), state_(GAME_MENU), keys_()
{
}

Game::~Game()
{
  //
}

void Game::LoadAssets()
{
}

void Game::ProcessInput(float dt)
{
  //
}

void Game::Update(float dt)
{
  //
}

void Game::Render()
{
  //
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