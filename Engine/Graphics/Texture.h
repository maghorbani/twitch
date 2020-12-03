#pragma once

#include <iostream>
#include <string>

class Texture {
  int id;
  int width;
  int height;

  bool loadImage(const char *, unsigned int);
  bool getTextureParams();

 public:
  Texture();
  Texture(int);          // id
  Texture(std::string);  // path

  int getId();
  int getWidth();
  int getHeight();
};