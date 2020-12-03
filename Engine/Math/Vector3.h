#pragma once

struct Vector3 {
  float x, y, z;

  Vector3();
  Vector3(float);
  Vector3(float, float);
  Vector3(float, float, float);

  Vector3(const Vector3 &);

  Vector3 operator+(Vector3 &) const;
  Vector3 &operator+=(Vector3 &);

  Vector3 operator=(Vector3);

  Vector3 operator-(Vector3 &);
  Vector3 &operator-=(Vector3 &);

  Vector3 operator*(float);

  bool operator==(Vector3 &);
  bool operator!=(Vector3 &);
};