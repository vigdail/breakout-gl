#include "level.h"
#include "entity_factory.h"

#include <glm/glm.hpp>
#include <fstream>
#include <iostream>

void Level::Load(std::filesystem::path&& file) {
  std::ifstream stream(file);
  if (!stream) {
    std::cerr << "ERROR::LEVEL: Unable to open file: " << file << std::endl;
    return;
  }

  stream >> width_ >> height_;
  tiles_ = std::vector<int>(width_ * height_);
  int i = 0;
  while (i < tiles_.size() && stream >> tiles_[i]) {
    i++;
  }
}

void Level::Init(entt::registry& registry) {
  auto view = registry.view<Block>();
  for (auto entity : view) {
    registry.destroy(entity);
  }

  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      float x = i * 128.0f;
      float y = j * 128.0f;
      int index = width_ * j + i;
      EntityFactory::CreateBlock(registry, glm::vec2(x, y),
                                 static_cast<BlockType>(tiles_[index]));
    }
  }
}
