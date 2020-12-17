#include "entity_factory.h"
#include "resources.h"

#include "resource_manager.h"

void EntityFactory::CreatePaddle(entt::registry &registry) {
  auto entity = registry.create();
  auto transform = Transform(128, 32);
  transform.position = glm::vec2(400.0f, 600.0f);
  transform.anchor = glm::vec2(0.5, 1.0f);
  registry.emplace<Transform>(entity, transform);
  registry.emplace<Sprite>(entity, ResourceManager::GetTexture("paddle"));
  registry.emplace<Player>(entity);
  registry.emplace<Collider>(entity);
}

void EntityFactory::CreateBlock(entt::registry &registry, glm::vec2 position,
                                glm::vec2 size, BlockType type) {
  if (type == BlockType::EMPTY) {
    return;
  }
  auto entity = registry.create();
  auto transform = Transform(size.x, size.y);
  transform.position = position;
  registry.emplace<Transform>(entity, transform);
  registry.emplace<Block>(entity);
  registry.emplace<Collider>(entity);

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

void EntityFactory::CreateBackground(entt::registry &registry) {
  auto entity = registry.create();
  WindowDimensions dimensions = registry.ctx<WindowDimensions>();
  registry.emplace<Transform>(entity, dimensions.width, dimensions.height);
  auto &sprite = registry.emplace<Sprite>(
      entity, ResourceManager::GetTexture("background"));
  sprite.z_index = -10;
}

entt::entity EntityFactory::CreateBall(entt::registry &registry,
                                       glm::vec2 position) {
  auto entity = registry.create();
  registry.emplace<Ball>(entity);
  auto &transform = registry.emplace<Transform>(entity, 32.0f, 32.0f);
  transform.position = position;
  transform.anchor = glm::vec2(0.5f);
  auto &sprite =
      registry.emplace<Sprite>(entity, ResourceManager::GetTexture("ball"));
  sprite.z_index = 10;

  return entity;
}

glm::vec3 EntityFactory::GetBlockColor(BlockType type) {
  switch (type) {
    case BlockType::GREEN:
      return glm::vec3(0.0f, 0.7f, 0.0f);
    case BlockType::BLUE:
      return glm::vec3(0.2f, 0.6f, 1.0f);
    case BlockType::YELLOW:
      return glm::vec3(0.8f, 0.8f, 0.4f);
    case BlockType::ORANGE:
      return glm::vec3(1.0f, 0.5f, 0.0f);
    default:
      return glm::vec3(1.0f);
  }
}
