#include "library.h"

const int motor_base_speed = 90;
int speed= 0;

//Include game_modes here
#include "game_modes/infinite_boost.h"
#include "game_modes/slow_speedup.h"
#include "game_modes/time_capped_boost.h"
#include "game_modes/presses_capped_boost.h"



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
    while (powerswitch()) {
      switch (selected_game_mode) {
        case 0: infinite_boost(); break;
        case 1: slow_speedup(); break;
        case 2: time_capped_boost(); break;
        case 3: presses_capped_boost(); break;
      }
    }
    stop();
    while (!powerswitch()) {
      delay(50);
    }
  }
}



