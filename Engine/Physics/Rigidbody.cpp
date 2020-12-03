#include "Engine/Physics/Rigidbody.h"
#include "Engine/Engine.h"

Rigidbody::Rigidbody(){
    friction = 1;
    gravity = 0;
}

void Rigidbody::initialize(float _friction, float _gravity, Vector3 * _pos, float *_rot, Vector3 *_scale, Vector3 *_size){
    friction = _friction;
    gravity = _gravity;

    pos = _pos;
    scale = _scale;
    zRot = _rot;
    size = _size;
}

void Rigidbody::Update(){

    vel.x *= friction;
    vel.y -= gravity;

    Vector3 tmp(vel * static_cast<float>(Engine::getDt()));
    *pos = *pos + tmp;
}

void Rigidbody::Render(Vector3 color){
    glLoadIdentity();

    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(*rot, 0, 0, 1);

    glColor4f(color.x,color.y, color.z, 1);
  glBegin(GL_LINES);
  {
//   glTexCoord2f(0, 0);
  glVertex2f(0, 0);
//   glTexCoord2f(1, 0);
  glVertex2f(size->x, 0);
//   glTexCoord2f(1, 1);
  glVertex2f(size->x, size->y);
//   glTexCoord2f(0, 1);
  glVertex2f(0, size->y);
  }
  glEnd();

}

void Rigidbody::AddForce(Vector3 f){
    vel = vel + f;
}