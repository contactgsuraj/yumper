#include "Ball.hpp"

Ball::Ball(std::string path, SDL_Renderer*& m_renderer) : Texture(path, m_renderer) {
  //int i = 0;
}

Ball::Ball() : Texture() {
}

Ball::~Ball() {
  // Deallocate
  //free();
}
