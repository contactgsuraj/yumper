#ifndef GRAVITY_H
#define GRAVITY_H

class Gravity {
 private:
  // g = 10ms-2
  int acceleration = -10;
  // u = 10ms-1
  int u = 10;

 public:
  Gravity();
  void process();
  float distanceMul = 1.5;
  float* varGravityPositions;
  int m_max_frame;
  float gravityPositions[33] = {
      0,       2.42188, 4.6875,  6.79688, 8.75,    10.5469, 12.1875,
      13.6719, 15,      16.1719, 17.1875, 18.0469, 18.75,   19.2969,
      19.6875, 19.9219, 20,      19.9219, 19.6875, 19.2969, 18.75,
      18.0469, 17.1875, 16.1719, 15,      13.6719, 12.1875, 10.5469,
      8.75,    6.79688, 4.6875,  2.42188, 0};
  float maxDist = 0;
};

#endif /* GRAVITY_H */
