#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"

struct Transform
{
  glm::vec3 position;
  glm::vec3 scale;
  float rotation;
  glm::vec3 anchor;
  Transform() : position(0.0f), scale(512.0f / 4.0f, 128.0f / 4.0f, 0.0f), rotation(0.0f), anchor(0.5f, 0.5f, 0.0f){};
  glm::mat4 Model() const
  {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, -anchor * scale);
    model = glm::scale(model, scale);

    return model;
  }
};

struct Sprite
{
  Texture texture;
  glm::vec3 color;
  Sprite(Texture texture) : texture(texture), color(glm::vec3(1.0f)){};
};

struct Renderable
{
};