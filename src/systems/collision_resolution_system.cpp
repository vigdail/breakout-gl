#include "collision_resolution_system.h"
#include <iostream>
#include "../components.h"
#include "../resources.h"
#include "../direction.h"

void CollisionResolutionSystem::Run(entt::registry &registry) {
  WindowDimensions dimensions = registry.ctx<WindowDimensions>();
  auto balls = registry.view<Ball, Transform, Velocity>();
  auto collisions = registry.view<Collision>();

  for (auto entity : collisions) {
    // @TODO: Store ball entity id in collision record
    auto &collision = registry.get<Collision>(entity);
    for (auto ball : balls) {
      auto &velocity = registry.get<Velocity>(ball);
      auto &transform = registry.get<Transform>(ball);

      float penetration = 0.0f;
      switch (collision.direction) {
        case Direction::UP:
          penetration =
              transform.size.y / 2.0f - std::abs(collision.position.y);
          velocity.value.y *= -1.0f;
          transform.position.y -= penetration;
          break;
        case Direction::DOWN:
          penetration =
              transform.size.y / 2.0f - std::abs(collision.position.y);
          velocity.value.y *= -1.0f;
          transform.position.y += penetration;
          break;
        case Direction::RIGHT:
          penetration =
              transform.size.x / 2.0f - std::abs(collision.position.x);
          velocity.value.x *= -1.0f;
          transform.position.x -= penetration;
          break;
        case Direction::LEFT:
          penetration =
              transform.size.x / 2.0f - std::abs(collision.position.x);
          velocity.value.x *= -1.0f;
          transform.position.x += penetration;
          break;
        default:
          break;
      }
    }
    registry.destroy(entity);
  }
}
