#pragma once

#include <map>
#include <string>
#include <filesystem>

#include "shader.h"
#include "texture.h"

namespace fs = std::filesystem;

class ResourceManager
{

private:
  static std::map<std::string, Shader> shaders_;
  static std::map<std::string, Texture> textures_;

  static Shader loadShaderFromFile(const fs::path vShaderFile, const fs::path fShaderFile, const fs::path gShaderFile = "");
  static Texture loadTextureFromFile(const fs::path path);

public:
  // ResourceManager() = delete;
  static Shader LoadShader(std::string name, const fs::path vShaderFile, const fs::path fShaderFile, const fs::path gShaderFile);
  static Shader GetShader(std::string name);

  static Texture LoadTexture(std::string name, const fs::path path);
  static Texture GetTexture(std::string name);
};