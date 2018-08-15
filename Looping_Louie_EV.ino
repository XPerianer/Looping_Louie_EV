#include "library.h"

const int motor_base_speed = 90;
int speed= 0;

//Include game_modes here
#include "game_modes/infinite_boost.h"
#include "game_modes/slow_speedup.h"
#include "game_modes/time_capped_boost.h"
#include "game_modes/presses_capped_boost.h"
#include "game_modes/random_boost.h"



void setup() {
  in_out_setup();
  digitalWrite(status_led, false);
}

void loop() { // This will run only to select the right game_mode
  int selected_game_mode = 0;

  while (!powerswitch()) {
    for (int i = 0; i < 4; i++) {
      if (pin(i)) {
        selected_game_mode++;
        digitalWrite(status_led, true);
        while (pin(i)) {
          delay(10);
        }
        digitalWrite(status_led, false);
      }
    }
  }

  while (true) {
    setup_infinite_boost();
    setup_slow_speedup();
    setup_time_capped_boost();
    setup_presses_capped_boost();
    setup_random_boost();
    while (powerswitch()) {
      switch (selected_game_mode) {
        case 1: random_boost(); break;
        case 2: slow_speedup(); break;
        case 3: presses_capped_boost(); break;
        case 4: infinite_boost(); break;
        case 5: motor(120); break; //Normal mode
        default: time_capped_boost(); break; // case 0
      }
    }
    stop();
    while (!powerswitch()) {
      delay(50);
    }
  }
}



