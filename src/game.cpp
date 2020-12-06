#include <iostream>

#include <glm/glm.hpp>

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