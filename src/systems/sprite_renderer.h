#pragma once

#include <entt/entt.hpp>
#include "../shader.h"

class SpriteRenderer
{
public:
  SpriteRenderer();
  ~SpriteRenderer();
  void Render(entt::registry &registry);

private:
  unsigned int VAO_;
  void InitVAO();
};
