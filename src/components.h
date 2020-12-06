#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Transform
{
  glm::vec3 position;
  glm::vec3 scale;
  float rotation;
  Transform() : position(0.0f), scale(1.0f), rotation(0.0f){};
  glm::mat4 Model() const
  {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, scale);

    return model;
  }
};

struct Sprite
{
  unsigned int texture;
};

struct Renderable
{
};