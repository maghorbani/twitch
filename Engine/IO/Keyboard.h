#pragma once

class GLFWwindow;
class Keyboard {
  static bool keys[];
  static bool keysDown[];
  static bool keysUp[];

public:
  static void keyCallback(GLFWwindow *, int key, int scanCode, int action,
                          int mods);

  static bool key(int);
  static bool keyUp(int);
  static bool keyDown(int);
};