const int boost_time = 3000;
const int allowed_presses = 1;

long left_presses[4];
long last_time_pressed;

void setup_time_capped_boost(){
	last_time_pressed = -boost_time;
	for (int i = 0; i < 4; i++){
    left_presses[i] = allowed_presses;
  }
}

void boostModeOn(){
  if (millis() - last_time_pressed < boost_time) return true;
  return false;
}

void time_capped_boost(){
    if (boostModeOn()) return;

    speed = motor_base_speed;
    for (int i = 0; i < 4; i++) {
      if (pin(i) && left_presses[i] > 0) {
        speed = 255;
		    left_presses[i] -= 1;
        last_time_pressed = millis;
      }
    }
    motor(speed);
}
