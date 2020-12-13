#include "entity_factory.h"

#include "resource_manager.h"

void EntityFactory::CreatePaddle(entt::registry &registry) {
  auto entity = registry.create();
  auto transform = Transform(128, 32);
  transform.position = glm::vec2(400.0f, 600.0f);
  transform.anchor = glm::vec2(0.5, 1.0f);
  registry.emplace<Transform>(entity, transform);
  registry.emplace<Sprite>(entity, ResourceManager::GetTexture("paddle"));
}

void EntityFactory::CreateBlock(entt::registry &registry, glm::vec2 position,
                                BlockType type) {
  if (type == BlockType::EMPTY) {
    return;
  }
  auto entity = registry.create();
  auto transform = Transform(128, 128);
  transform.position = position;
  registry.emplace<Transform>(entity, transform);
  registry.emplace<Block>(entity);

  if (type == BlockType::UNBREAKABLE) {
    registry.emplace<Sprite>(entity,
                             ResourceManager::GetTexture("block_solid"));
    registry.emplace<Unbreakable>(entity);
  } else {
    glm::vec3 color = GetBlockColor(type);
    registry.emplace<Sprite>(entity, ResourceManager::GetTexture("block"),
                             color);
  }
}

glm::vec3 EntityFactory::GetBlockColor(BlockType type) {
  switch (type) {
    case BlockType::RED:
      return glm::vec3(1.0f, 0.0f, 0.0f);
    case BlockType::GREEN:
      return glm::vec3(0.0f, 1.0f, 0.0f);
    case BlockType::BLUE:
      return glm::vec3(0.0f, 0.0f, 1.0f);
    default:
      return glm::vec3(1.0f);
  }
}
