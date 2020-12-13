#include "input_system.h"
#include "../components.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

void InputSystem::Run(entt::registry &registry, const bool keys[]) {
  Velocity velocity;
  if (keys[GLFW_KEY_A]) {
    velocity.value += glm::vec2(-500.0f, 0.0f);
  }
  if (keys[GLFW_KEY_D]) {
    velocity.value += glm::vec2(500.0f, 0.0f);
  }

  auto view = registry.view<Player>();
  for (auto entity : view) {
    registry.emplace_or_replace<Velocity>(entity, velocity);
  }
}
