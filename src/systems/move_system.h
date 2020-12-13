#pragma once

#include <entt/entt.hpp>
#include <glm/glm.hpp>

class MoveSystem {
 public:
  void Run(entt::registry &registry, float dt);
};
