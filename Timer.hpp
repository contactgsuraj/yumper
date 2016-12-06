#ifndef TIMER_H
#define TIMER_H
#include <cstdio>
#include <cstdint>
#include <SDL2/SDL.h>

class Timer

{
 public:
  Timer();

  void start();
  void stop();
  void pause();
  void unpause();

  uint32_t get_ticks();

  bool is_started();
  bool is_paused();

 private:
  uint32_t m_start_ticks;

  uint32_t m_paused_ticks;

  bool m_paused;
  bool m_started;
};
#endif /* TIMER_H */
