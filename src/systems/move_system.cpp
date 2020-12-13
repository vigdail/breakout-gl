#include "move_system.h"
#include "../components.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

void MoveSystem::Run(entt::registry &registry, float dt) {
  auto view = registry.view<Transform, Velocity>();

  for (auto entity : view) {
    Velocity velocity = registry.get<Velocity>(entity);
    registry.remove<Velocity>(entity);

    Transform &transform = registry.get<Transform>(entity);
    transform.position += velocity.value * dt;
  }
}
