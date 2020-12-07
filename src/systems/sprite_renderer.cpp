#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "sprite_renderer.h"
#include "../components.h"
#include "../resource_manager.h"

SpriteRenderer::SpriteRenderer()
{
  InitVAO();
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Render(entt::registry &registry)
{
  glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
  glActiveTexture(GL_TEXTURE0);
  Shader shader = ResourceManager::GetShader("sprite");
  shader
      .Use()
      .SetMat4("projection", projection)
      .SetVec3("color", glm::vec3(1.0f, 0.0f, 0.0f));
  glBindVertexArray(VAO_);

  auto view = registry.view<Transform, Sprite>();

  for (auto &entity : view)
  {
    glBindTexture(GL_TEXTURE_2D, registry.get<Sprite>(entity).texture);
    auto transform = registry.get<Transform>(entity);
    glm::mat4 model = transform.Model();
    shader.SetMat4("model", model);

    glDrawArrays(GL_TRIANGLES, 0, 6);
  }
}

void SpriteRenderer::InitVAO()
{
  const float vertices[] = {
      // pos      // tex
      0.0f, 1.0f, 0.0f, 1.0f,
      1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f,

      0.0f, 1.0f, 0.0f, 1.0f,
      1.0f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.0f, 1.0f, 0.0f};

  glGenVertexArrays(1, &VAO_);

  unsigned int VBO;
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(VAO_);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void *)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void *)(sizeof(float) * 2));

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
