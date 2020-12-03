#pragma once

class GLFWwindow;

class Engine {
  static int width;
  static int height;
  static GLFWwindow *window;
  static double dt;
  static double lastTime;

public:
  Engine();
  ~Engine();

  static double getDt();

  bool Initialize(const char *);

  void Update();
  void BeginRender();
  void EndRender();
};