#include "sprite_renderer.h"

#include <glad/glad.h>
#include <iostream>

#include "../components.h"
#include "../resource_manager.h"

SpriteRenderer::SpriteRenderer(unsigned int width, unsigned int height)
    : projection_(glm::ortho(0.0f, static_cast<float>(width),
                             static_cast<float>(height), 0.0f, -1.0f, 1.0f)) {
  InitVAO();
}

void SpriteRenderer::Render(entt::registry &registry) {
  // @TODO: Need to cache order, or at least move this to separate system
  registry.sort<Sprite>([](const auto &lhs, const auto &rhs) {
    return lhs.z_index < rhs.z_index;
  });
  registry.sort<Transform, Sprite>();

  glActiveTexture(GL_TEXTURE0);
  Shader shader = ResourceManager::GetShader("sprite");
  shader.Use().SetMat4("projection", projection_);
  glBindVertexArray(VAO_);

  auto view = registry.view<Transform, Sprite>();

  for (auto &entity : view) {
    auto sprite = registry.get<Sprite>(entity);
    sprite.texture.Bind();
    auto transform = registry.get<Transform>(entity);
    glm::mat4 model = transform.Model();
    shader.SetMat4("model", model).SetVec3("color", sprite.color);

    glDrawArrays(GL_TRIANGLES, 0, 6);
  }
}

void SpriteRenderer::InitVAO() {
  const float vertices[] = {0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
                            1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f};

  glGenVertexArrays(1, &VAO_);

  unsigned int VBO;
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(VAO_);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4,
                        static_cast<void *>(0));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4,
                        static_cast<void *>(0) + sizeof(float) * 2);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
