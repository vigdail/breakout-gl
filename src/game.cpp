#include <iostream>

#include <glm/glm.hpp>

#include "application.h"
#include "game.h"

Game::Game(uint width, uint height)
    : width_(width), height_(height), state_(GAME_MENU), keys_()
{
  std::cout << "Game was created" << std::endl;
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
  if (keys_[GLFW_KEY_W])
  {
    std::cout << "Key[W] pressed" << std::endl;
  }
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
  if (key >= 0 && key < 1024)
  {
    keys_[key] = true;
  }
}

void Game::SetKeyReleased(uint key)
{
  if (key >= 0 && key < 1024)
  {
    keys_[key] = false;
  }
}

bool Game::IsKeyPressed(uint key)
{
  if (key >= 0 && key < 1024)
  {
    return keys_[key];
  }

  return false;
}