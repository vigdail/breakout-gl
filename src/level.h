#pragma once

#include <filesystem>
#include <vector>

#include <entt/entt.hpp>

class Level {
 private:
  std::vector<int> tiles_;
  int width_;
  int height_;

 public:
  Level() {}
  void Load(std::filesystem::path&& file);
  void Init(entt::registry& registry);
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
};
