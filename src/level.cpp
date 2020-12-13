#include "level.h"
#include "entity_factory.h"
#include "resources.h"

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
  tiles_ = std::vector<BlockType>(width_ * height_);
  int i = 0;
  int temp;
  while (i < tiles_.size() && stream >> temp) {
    tiles_[i] = static_cast<BlockType>(temp);
    i++;
  }
}

void Level::Init(entt::registry& registry) {
  auto view = registry.view<Block>();
  for (auto entity : view) {
    registry.destroy(entity);
  }

  WindowDimensions dimensions = registry.ctx<WindowDimensions>();
  float block_width =
      static_cast<float>(dimensions.width) / static_cast<float>(width_);
  float block_height = static_cast<float>(dimensions.height) /
                       static_cast<float>(height_) / 2.0f;

  registry.set<BlockSize>(block_width, block_height);

  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      float x = i * block_width;
      float y = j * block_height;
      int index = width_ * j + i;
      EntityFactory::CreateBlock(registry, glm::vec2(x, y),
                                 glm::vec2(block_width, block_height),
                                 tiles_[index]);
    }
  }
}
