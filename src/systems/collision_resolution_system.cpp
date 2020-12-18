#include "collision_resolution_system.h"
#include <iostream>
#include "../components.h"
#include "../resources.h"
#include "../direction.h"

void CollisionResolutionSystem::Run(entt::registry &registry) {
  CollideWithBlocks(registry);
  CollideWithPaddles(registry);
}

void CollisionResolutionSystem::CollideWithBlocks(entt::registry &registry) {
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

void CollisionResolutionSystem::CollideWithPaddles(entt::registry &registry) {
  auto balls = registry.view<Ball, Transform, Velocity>();
  auto collisions = registry.view<PaddleCollision>();

  for (auto entity : collisions) {
    // @TODO: Store ball entity id in collision record
    auto &collision = registry.get<PaddleCollision>(entity);
    auto transform = registry.get<Transform>(collision.paddle);
    for (auto ball : balls) {
      auto &ball_transform = registry.get<Transform>(ball);
      auto &velocity = registry.get<Velocity>(ball);
      float distance = ball_transform.Center().x - transform.Center().x;

      float percentage = distance / (transform.size.x / 2.0f);

      glm::vec2 old_velocity = velocity.value;
      // @TODO: Make default ball velocity to be context variable
      velocity.value.x = 200.0f * percentage * 2.0f;
      velocity.value.y *= -1.0f;
      velocity.value =
          glm::normalize(velocity.value) * glm::length(old_velocity);
    }
    registry.destroy(entity);
  }
}
