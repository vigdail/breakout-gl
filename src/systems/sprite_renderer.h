#pragma once

#include <glm/glm.hpp>

#include <entt/entt.hpp>
#include "../shader.h"

class SpriteRenderer
{
public:
  SpriteRenderer(unsigned int width, unsigned int height);
  void Render(entt::registry &registry);

private:
  unsigned int VAO_;
  void InitVAO();
  glm::mat4 projection_;
};
