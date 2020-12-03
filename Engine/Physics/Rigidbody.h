#pragma once

#include "Engine/Math/Vector3.h"
class Rigidbody {
  Vector3 *pos;
  Vector3 *scale;
  Vector3 *size;
  float *zRot;

  float gravity;
  float friction;


  Vector3 vel;
public:
  Rigidbody();

  void initialize(float, float, Vector3 *, float *, Vector3 *, Vector3 *);//fric, gravity, pos, zRot, scale, size

  void Update();
  void Render(Vector3);//color

  void addForce(Vector3);//force

};