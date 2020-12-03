#pragma once

class GLFWwindow;

class Mouse {
  static double x;
  static double y;

  static bool buttons[];
  static bool buttonsDown[];
  static bool buttonsUp[];

public:
  static void mousePosCallback(GLFWwindow *, double, double);
  static void mouseButtonCallback(GLFWwindow *, int, int,
                                  int); // button, action, mods
  static double getMouseX();
  static double getMouseY();

  static bool ButtonDown(int);
  static bool ButtonUp(int);
  static bool Button(int);
};