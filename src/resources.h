#pragma once

struct WindowDimensions {
  int width;
  int height;
  WindowDimensions(int width, int height) : width(width), height(height) {}
};

struct BlockSize {
  int width;
  int height;
  BlockSize(int width, int height) : width(width), height(height) {}
};

struct State {
  glm::vec2 ball_initial_velocity;
  State() : ball_initial_velocity(glm::vec2(200.0f, -200.0f)) {}
};
