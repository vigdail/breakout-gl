#include <iostream>

#include <stb_image.h>

#include "resource_manager.h"

std::map<std::string, Texture> ResourceManager::textures_;
std::map<std::string, Shader> ResourceManager::shaders_;

Shader ResourceManager::LoadShader(std::string name, const fs::path vShaderFile, const fs::path fShaderFile, const fs::path gShaderFile)
{
  shaders_[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
  return shaders_[name];
}

Shader ResourceManager::GetShader(std::string name)
{
  return shaders_[name];
}

Texture ResourceManager::LoadTexture(std::string name, const fs::path path)
{
  textures_[name] = loadTextureFromFile(path);
  return textures_[name];
}
Texture ResourceManager::GetTexture(std::string name)
{
  return textures_[name];
}

Shader ResourceManager::loadShaderFromFile(const fs::path vShaderFile, const fs::path fShaderFile, const fs::path gShaderFile)
{
  Shader s("", "", "");
  return s;
}
Texture ResourceManager::loadTextureFromFile(const fs::path path)
{
  int width;
  int height;
  int n_channels;

  unsigned char *data = stbi_load(path.c_str(), &width, &height, &n_channels, 0);

  if (!data)
  {
    std::cerr << "ERROR::TEXTURE: Unable to load texture from file: " << path << std::endl;
  }

  Texture texture;
  if (n_channels == 1)
  {
    texture.image_format = GL_RED;
    texture.internal_format = GL_RED;
  }
  else if (n_channels == 4)
  {
    texture.image_format = GL_RGBA;
    texture.internal_format = GL_RGBA;
  }

  texture.Generate(width, height, data);
  stbi_image_free(data);

  return texture;
}