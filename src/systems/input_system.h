#pragma once

#include <entt/entt.hpp>
#include <glm/glm.hpp>

class InputSystem {
 public:
  void Run(entt::registry &registry, const bool keys[]);
};
