#pragma once

#include <entt/entt.hpp>

#include "components.h"

enum class BlockType {
  EMPTY = 0,
  UNBREAKABLE = 1,
  RED,
  GREEN,
  BLUE,
};

class EntityFactory {
 public:
  static void CreatePaddle(entt::registry &registry);
  static void CreateBlock(entt::registry &registry, glm::vec2 position,
                          BlockType type);

 private:
  static glm::vec3 GetBlockColor(BlockType type);
};
