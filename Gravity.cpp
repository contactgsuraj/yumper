#include "Gravity.hpp"
#include <iostream>
Gravity::Gravity() {
  process(); 
}
void Gravity::process() {
  int frame = 0;
  int INIT_SPEED = 50;
  float u = INIT_SPEED;
  float v;
  float acceleration = -19.0;
  float timem;
  float timDivider = 6;
  int loops;
  while (true) {
    timem = ((float)frame / timDivider);
    v = u + (acceleration * timem);
    if (v <= (-1 * u)) {
      break;
    }
    ++frame;
  }
  loops = frame;
  m_max_frame = (int)(frame - 1);
  varGravityPositions = new float[frame];
  u = INIT_SPEED;
  for ( int i= 0; i < loops; i++) {
    timem = ((float)i / timDivider);
    v = u + (acceleration * timem);
    float position = ((v * v) - (u * u)) / (2 * acceleration);
    if (position == -0) {
      position = 0;
    }
    if (position < 0 ) {
      std::cerr << "POSITION LOWER THAN EXPECTED" << std::endl; 
      std::cerr << position << std::endl; 
    }
    varGravityPositions[i] = position;
  }
}
