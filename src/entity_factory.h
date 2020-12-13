#pragma once

#include <entt/entt.hpp>

#include "components.h"

enum class BlockType {
  EMPTY = 0,
  UNBREAKABLE = 1,
  GREEN,
  BLUE,
  YELLOW,
  ORANGE,
};

class EntityFactory {
 public:
  static void CreatePaddle(entt::registry &registry);
  static void CreateBlock(entt::registry &registry, glm::vec2 position,
                          glm::vec2 size, BlockType type);
  static void CreateBackground(entt::registry &registry);

 private:
  static glm::vec3 GetBlockColor(BlockType type);
};
