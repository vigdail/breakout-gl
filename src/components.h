#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "./texture.h"

struct Transform {
  glm::vec2 position;
  glm::vec2 size;
  float rotation;
  glm::vec2 anchor;
  Transform(int width, int height)
      : position(0.0f),
        size(glm::vec2(static_cast<float>(width), static_cast<float>(height))),
        rotation(0.0f),
        anchor(0.0f) {}

  glm::mat4 Model() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model =
        glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-anchor * size, 0.0f));
    model = glm::scale(model, glm::vec3(size, 0.0f));

    return model;
  }

  float Left() const { return position.x - anchor.x * size.x; }
  float Right() const { return position.x + (1.0f - anchor.x) * size.x; }
  float Top() const { return position.y - anchor.y * size.y; }
  float Bottom() const { return position.y + (1.0f - anchor.y) * size.y; }

  void SetLeft(float left) { position.x = left + anchor.x * size.x; }
  void SetRight(float right) {
    position.x = right - (1.0f - anchor.x) * size.x;
  }
  void SetTop(float top) { position.y = top + anchor.y * size.y; }
  void SetBottom(float bottom) {
    position.y = bottom - (1.0f - anchor.y) * size.y;
  }

  glm::vec2 Center() const {
    float x = (Left() + Right()) / 2.0f;
    float y = (Top() + Bottom()) / 2.0f;
    return glm::vec2(x, y);
  }
};

struct Sprite {
  Texture texture;
  glm::vec3 color;
  int z_index;
  explicit Sprite(Texture texture, glm::vec3 color = glm::vec3(1.0f))
      : texture(texture), color(color), z_index(0) {}
};

struct Velocity {
  glm::vec2 value;
  Velocity() : value(0.0f) {}
  explicit Velocity(glm::vec2 value) : value(value) {}
};

struct Renderable {};
struct Player {};
struct Ball {};
struct Collider {};

struct Block {};

struct Unbreakable {};
