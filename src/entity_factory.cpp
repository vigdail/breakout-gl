#include "entity_factory.h"
#include "resource_manager.h"

void EntityFactory::CreatePaddle(entt::registry &registry)
{
  auto entity = registry.create();
  auto transform = Transform(128, 32);
  transform.position = glm::vec2(400.0f, 600.0f);
  transform.anchor = glm::vec2(0.5, 1.0f);
  registry.emplace<Transform>(entity, transform);
  registry.emplace<Sprite>(entity, ResourceManager::GetTexture("paddle"));
}

void EntityFactory::CreateBlock(entt::registry &registry, glm::vec2 position, int type)
{
  auto entity = registry.create();
  auto transform = Transform(128, 128);
  transform.position = position;
  registry.emplace<Transform>(entity, transform);
  registry.emplace<Block>(entity);

  if (type != 1)
  {
    glm::vec3 color = GetBlockColor(type);
    registry.emplace<Sprite>(entity, ResourceManager::GetTexture("block"), color);
  }
  else
  {
    registry.emplace<Sprite>(entity, ResourceManager::GetTexture("block_solid"));
    registry.emplace<Unbreakable>(entity);
  }
}

glm::vec3 EntityFactory::GetBlockColor(int type)
{
  switch (type)
  {
  case 2:
    return glm::vec3(1.0f, 0.0f, 0.0f);
  case 3:
    return glm::vec3(0.0f, 1.0f, 0.0f);
  case 4:
    return glm::vec3(0.0f, 0.0f, 1.0f);
  default:
    return glm::vec3(1.0f);
  }
}