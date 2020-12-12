#pragma once

#include <entt/entt.hpp>
#include <glm/glm.hpp>

#include "../shader.h"

class SpriteRenderer {
 public:
  SpriteRenderer(unsigned int width, unsigned int height);
  void Render(entt::registry *registry);

 private:
  void InitVAO();
  unsigned int VAO_;
  glm::mat4 projection_;
};
