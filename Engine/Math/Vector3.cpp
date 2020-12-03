#include "Engine/Math/Vector3.h"

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float a) : x(a), y(a), z(a) {}
Vector3::Vector3(float x, float y) : Vector3(x, y, 0) {}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3 &other) : Vector3(other.x, other.y, other.z) {}

Vector3 Vector3::operator+(Vector3 &other) const {
  Vector3 ret(other);
  ret.x += x;
  ret.y += y;
  ret.z += z;
  return ret;
}
Vector3 &Vector3::operator+=(Vector3 &other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

Vector3 Vector3::operator=(Vector3 other) {
  x = other.x;
  y = other.y;
  z = other.z;
  return *this;
}

Vector3 Vector3::operator-(Vector3 &other) {
  Vector3 ret(other);
  ret.x -= x;
  ret.y -= y;
  ret.z -= z;
  return ret;
}
Vector3 &Vector3::operator-=(Vector3 &other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

bool Vector3::operator==(Vector3 &other) {
  return (x == other.x) && (y == other.y) && (z == other.z);
}
bool Vector3::operator!=(Vector3 &other) { return !(*this == other); }

Vector3 Vector3::operator*(float scale) {
  x *= scale;
  y *= scale;
  z *= scale;
  return *this;
}