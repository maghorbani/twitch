#pragma once

#include <iostream>
#include <string>

#include "Engine/Math/Vector3.h"

class Texture;

class Sprite {
  Texture *texture;
  Vector3 pos;
  Vector3 scale;
  float zRot;

  float speed;

public:
  Sprite();
  Sprite(std::string);          // imagePath
  Sprite(std::string, Vector3); // imagePath
  ~Sprite();

  void Update();
  void Render();

  void setPos(Vector3);
  void setZRot(float);
  void addZRot(float);

  void moveInX(float);
  void moveInY(float);
  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();

  void setSpeed(float);
  void addSpeed(float);

  void setScale(float);
  void setScale(Vector3);
};