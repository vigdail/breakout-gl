#pragma once

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
  Shader(){};
  Shader(const char *vertex_source, const char *fragment_source, const char *geometry_source = nullptr);
  ~Shader();
  Shader &Use();
  Shader &SetInt(const char *name, const int value);
  Shader &SetFloat(const char *name, const float value);
  Shader &SetVec3(const char *name, const glm::vec3 &value);
  Shader &SetMat4(const char *name, const glm::mat4 &value);

private:
  GLuint ID_;
  void CheckCompileErrors(uint object, std::string type);
};
