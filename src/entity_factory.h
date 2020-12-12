#pragma once

#include <entt/entt.hpp>

#include "components.h"

class EntityFactory {
 public:
  static void CreatePaddle(entt::registry &registry);
  static void CreateBlock(entt::registry &registry, glm::vec2 position,
                          int type);

 private:
  static glm::vec3 GetBlockColor(int type);
};
