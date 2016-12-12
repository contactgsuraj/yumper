#ifndef BALL_H
#define BALL_H
#include <string>
#include "Texture.hpp"

class Ball : public Texture {
 private:
 public:
  Ball(SDL_Renderer*&);
  Ball(std::string path, SDL_Renderer*& m_renderer);
  ~Ball();
};

#endif /* BALL_H*/
