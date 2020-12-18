#pragma once

#include <entt/entt.hpp>

class CollisionResolutionSystem {
 public:
  void Run(entt::registry &registry);

 private:
  void CollideWithBlocks(entt::registry &registry);
  void CollideWithPaddles(entt::registry &registry);
};
