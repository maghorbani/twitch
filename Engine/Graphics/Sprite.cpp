
#include "Engine/Graphics/Sprite.h"
#include "Engine/Engine.h"
#include "Engine/Graphics/Texture.h"
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

Sprite::Sprite() : pos(Vector3()), scale(Vector3()), zRot(0), speed(5) {
  texture = new Texture();
}

Sprite::Sprite(std::string path)
    : pos(Vector3()), scale(Vector3()), zRot(0), speed(5) {
  texture = new Texture(path);
}

Sprite::Sprite(std::string path, Vector3 _pos)
    : pos(_pos), scale(Vector3()), zRot(0), speed(5) {
  texture = new Texture(path);
}

Sprite::~Sprite() { delete texture; }

void Sprite::Update() {}

void Sprite::Render() {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture->getId());
  glLoadIdentity();

  // spdlog::debug("{}, {}", xPos, yPos);
  // Translate, Rotate, Scale
  glTranslatef(pos.x, pos.y, 0);
  glRotatef(zRot, 0, 0, 1);
  glScalef(scale.x, scale.y, 1);
  // Rendering
  glColor4f(1, 1, 1, 1);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2f(0, 0);
  glTexCoord2f(1, 0);
  glVertex2f(texture->getWidth(), 0);
  glTexCoord2f(1, 1);
  glVertex2f(texture->getWidth(), texture->getHeight());
  glTexCoord2f(0, 1);
  glVertex2f(0, texture->getHeight());
  glEnd();

  glDisable(GL_TEXTURE_2D);
}

void Sprite::setPos(Vector3 _pos) { pos = _pos * speed; }

void Sprite::setZRot(float rot) { zRot = rot; }
void Sprite::addZRot(float rot) { zRot += rot; }

void Sprite::setScale(float s) { scale = Vector3(s); }
void Sprite::setScale(Vector3 _scale) { scale = _scale; }

void Sprite::moveInX(float s) { pos.x += s * Engine::getDt(); }
void Sprite::moveInY(float s) { pos.y += s * Engine::getDt(); }
void Sprite::moveRight() { pos.x += speed * Engine::getDt(); }
void Sprite::moveLeft() { pos.x -= speed * Engine::getDt(); }
void Sprite::moveUp() { pos.y += speed * Engine::getDt(); }
void Sprite::moveDown() { pos.y -= speed * Engine::getDt(); }

void Sprite::setSpeed(float s) { speed = s; }
void Sprite::addSpeed(float s) { speed += s; }