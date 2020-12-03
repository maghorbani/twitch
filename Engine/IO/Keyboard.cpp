#include "Engine/IO/Keyboard.h"

#include <GLFW/glfw3.h>

bool Keyboard::keys[GLFW_KEY_LAST] = {0};
bool Keyboard::keysUp[GLFW_KEY_LAST] = {0};
bool Keyboard::keysDown[GLFW_KEY_LAST] = {0};

void Keyboard::keyCallback(GLFWwindow *, int key, int scanCode, int action,
                           int mods) {
  if (key < 0)
    return;
  if (action != GLFW_RELEASE && keys[key] == false) {
    keysUp[key] = false;
    keysDown[key] = true;
  }
  if (action == GLFW_RELEASE && keys[key] == true) {
    keysUp[key] = true;
    keysDown[key] = false;
  }

  keys[key] = action != GLFW_RELEASE;
}
bool Keyboard::keyUp(int i) {
  bool x{keysUp[i]};
  keysUp[i] = false;
  return x;
}
bool Keyboard::keyDown(int i) {
  bool x{keysDown[i]};
  keysDown[i] = false;
  return x;
}
bool Keyboard::key(int i) { return keys[i]; }