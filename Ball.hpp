#ifndef BALL_H
#define BALL_H
#include "Texture.hpp"
#include <string>

class Ball : public Texture {
 private:
 public:
  Ball(std::string path, SDL_Renderer*& m_renderer);
};

#endif /* BALL_H*/
