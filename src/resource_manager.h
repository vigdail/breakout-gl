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

  static Shader loadShaderFromFile(const fs::path &v_shader_path, const fs::path &f_shader_path, const fs::path &g_shader_path);
  static Texture loadTextureFromFile(const fs::path &path);

public:
  ResourceManager() = delete;
  static Shader LoadShader(std::string name, const fs::path &v_shader_path, const fs::path &f_shader_path, const fs::path &g_shader_path = "");
  static Shader GetShader(std::string name);

  static Texture LoadTexture(std::string name, const fs::path &path);
  static Texture GetTexture(std::string name);
};