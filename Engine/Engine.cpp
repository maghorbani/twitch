#include "Engine/Engine.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/IO/Mouse.h"
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

int Engine::width = 1024;
int Engine::height = 768;
double Engine::dt = 0;
double Engine::lastTime = 0;
GLFWwindow *Engine::window = nullptr;

Engine::Engine() {}

Engine::~Engine() {}

bool Engine::Initialize(const char *windowTitle) {
  if (!glfwInit()) {
    spdlog::error("Error Initializing GLFW");
    return false;
  }

  window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);

  if (window == nullptr) {
    spdlog::error("Error Creating window");
    return false;
  }

  // OpenGL Setup
  glfwMakeContextCurrent(window);
  int local_width, local_height;
  glfwGetFramebufferSize(window, &local_width, &local_height);
  glfwSwapInterval(1);

  glfwSetCursorPosCallback(window, Mouse::mousePosCallback);
  glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);

  glfwSetKeyCallback(window, Keyboard::keyCallback);

  const GLFWvidmode *mode{glfwGetVideoMode(glfwGetPrimaryMonitor())};

  int xPos{(mode->width - width) / 2};
  int yPos{(mode->height - height) / 2};

  glfwSetWindowPos(window, xPos, yPos);

  // GL Setup
  // Viewport
  glViewport(0, 0, local_width, local_height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, local_width, 0, local_height, -10, 10);
  glDepthRange(-10, 10);
  glMatrixMode(GL_MODELVIEW);

  // Alpha Blending
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  lastTime = glfwGetTime();

  return true;
}

void Engine::Update() {
  double now = glfwGetTime();
  dt = now - lastTime;
  lastTime = now;
  glfwPollEvents();
}

void Engine::BeginRender() {
  glClearColor(0, 1, 0, 1); // clear backbuffer with blue color
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender() { glfwSwapBuffers(window); }

double Engine::getDt() { return dt; }