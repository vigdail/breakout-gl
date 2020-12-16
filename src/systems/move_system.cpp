#include "move_system.h"
#include "../components.h"
#include "../resources.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

void MoveSystem::Run(entt::registry &registry, float dt) {
  WindowDimensions dimensions = registry.ctx<WindowDimensions>();

  auto view = registry.view<Transform, Velocity>();

  for (auto entity : view) {
    Velocity velocity = registry.get<Velocity>(entity);

    Transform &transform = registry.get<Transform>(entity);
    transform.position += velocity.value * dt;
  }
}
