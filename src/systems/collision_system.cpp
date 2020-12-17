#include "collision_system.h"
#include "../components.h"
#include "../resources.h"

void CollisionSystem::Run(entt::registry &registry) {
  WindowDimensions dimensions = registry.ctx<WindowDimensions>();
  auto balls = registry.view<Ball, Transform, Velocity>();
  auto view = registry.view<Transform, Collider>();

  for (auto ball_entity : balls) {
    auto &ball_transform = registry.get<Transform>(ball_entity);
    auto &ball_velocity = registry.get<Velocity>(ball_entity);
    // screen
    if (ball_transform.Left() < 0.0f) {
      ball_transform.SetLeft(0.0f);
      ball_velocity.value.x *= -1;
    }
    if (ball_transform.Right() > dimensions.width) {
      ball_transform.SetRight(dimensions.width);
      ball_velocity.value.x *= -1;
    }
    if (ball_transform.Top() < 0.0f) {
      ball_transform.SetTop(0.0f);
      ball_velocity.value.y *= -1;
    }
    if (ball_transform.Bottom() > dimensions.height) {
      ball_transform.SetBottom(dimensions.height);
      ball_velocity.value.y *= -1;
    }

    glm::vec2 ball_center = ball_transform.Center();
    for (auto entity : view) {
      auto transform = registry.get<Transform>(entity);

      glm::vec2 aabb_half_extends(transform.size.x / 2.0f,
                                  transform.size.y / 2.0f);
      glm::vec2 aabb_center = transform.Center();
      glm::vec2 difference = ball_center - aabb_center;
      glm::vec2 clamped =
          glm::clamp(difference, -aabb_half_extends, aabb_half_extends);

      glm::vec2 closest = aabb_center + clamped;

      difference = closest - ball_center;

      if (glm::length(difference) < ball_transform.size.x / 2.0f) {
        if (registry.has<Block>(entity) && !registry.has<Unbreakable>(entity)) {
          registry.destroy(entity);
        }
      }
    }
  }
}
