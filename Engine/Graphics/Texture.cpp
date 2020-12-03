#include "Engine/Graphics/Texture.h"

#include <GLFW/glfw3.h>
#include <SOIL2/SOIL2.h>
#include <spdlog/spdlog.h>

Texture::Texture() : id(-1) {}

Texture::Texture(int _id) : id(_id) {
  if (!getTextureParams()) {
    spdlog::error("Texture: Error Loading Image with ID {}", id);
  }
}

Texture::Texture(std::string path) {
  bool imageLoaded =
      loadImage(path.c_str(), SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
  if (!imageLoaded) {
    spdlog::error("Texture: Error Loading Image {}", path);
  }
}

bool Texture::loadImage(const char *path, unsigned int flags) {
  id = SOIL_load_OGL_texture(path, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, flags);
  return getTextureParams();
}

bool Texture::getTextureParams() {
  if (id > 0) {
    int mipLevel{};
    glBindTexture(GL_TEXTURE_2D, id);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT,
                             &height);

    return true;
  }
  return false;
}

int Texture::getId() { return id; }

int Texture::getWidth() { return width; }

int Texture::getHeight() { return height; }