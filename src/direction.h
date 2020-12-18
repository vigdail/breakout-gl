#pragma once

#include <glm/glm.hpp>

enum class Direction {
  UP,
  RIGHT,
  DOWN,
  LEFT,
};

Direction VectorDirection(glm::vec2 target);
