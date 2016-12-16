#include "Collision.hpp"
Collision::Collision(std::shared_ptr<Bob> bob) {
  bob_c = bob; 
}
void Collision::spike_detect() {
  if (bob_c->get_y() > (SCREEN_HEIGHT - 150 - 120) + 5) { 
    bob_c->is_dead = true;
  }
}
