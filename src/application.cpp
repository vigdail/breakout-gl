#include <iostream>

#include "application.h"

Application::Application(unsigned int width, unsigned int height) : game_(width, height), width_(width), height_(height)
{
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, false);

  window_ = glfwCreateWindow(width, height, "Breakout GL", nullptr, nullptr);
  glfwMakeContextCurrent(window_);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }

  glfwSetKeyCallback(window_, key_callback);
  glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
}

Application::~Application()
{
  glfwTerminate();
}

void Application::Run()
{
  while (!glfwWindowShouldClose(window_))
  {
    glfwPollEvents();
  }
}

void Application::key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}

void Application::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
}