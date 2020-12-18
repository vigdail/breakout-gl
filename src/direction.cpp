#include "direction.h"

Direction VectorDirection(glm::vec2 target) {
  glm::vec2 compass[] = {
      glm::vec2(0.0f, 1.0f),
      glm::vec2(1.0f, 0.0f),
      glm::vec2(0.0f, -1.0f),
      glm::vec2(-1.0f, 0.0f),
  };

  float max = 0.0f;
  int best_match = -1;
  for (int i = 0; i < 4; i++) {
    float dot_prod = glm::dot(glm::normalize(target), compass[i]);
    if (dot_prod > max) {
      max = dot_prod;
      best_match = i;
    }
  }

  return static_cast<Direction>(best_match);
}
