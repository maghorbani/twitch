#include "Engine/Engine.h"
#include <iostream>
#include <spdlog/spdlog.h>

#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/IO/Mouse.h"

#include <GLFW/glfw3.h>

int main(int argc, char *argv[]) {
  spdlog::set_level(spdlog::level::trace);
  spdlog::debug("Program started");

  Engine engine;
  engine.Initialize("My Window");

  Sprite testSprite("../Assets/Art/BiPlane.png");
  testSprite.setScale(0.4);
  testSprite.setSpeed(100);
  // test

  while (true) {
    engine.Update();
    testSprite.Update();
    // testSprite.setPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
    if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_LEFT)) {
      testSprite.addZRot(10);
    }
    if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
      testSprite.addZRot(-10);
    }
    if (Keyboard::key(GLFW_KEY_W)) {
      testSprite.moveUp();
    }
    if (Keyboard::key(GLFW_KEY_S)) {
      testSprite.moveDown();
    }
    if (Keyboard::key(GLFW_KEY_D)) {
      testSprite.moveRight();
    }
    if (Keyboard::key(GLFW_KEY_A)) {
      testSprite.moveLeft();
    }

    engine.BeginRender();
    testSprite.Render();
    engine.EndRender();
  }
  return 0;
}