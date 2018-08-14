const int boost_duration = 3000;
const int allowed_presses = 1;

long left_presses[4];
long last_time_pressed;
bool button_down_before[4];

void setup_presses_capped_boost(){
	last_time_pressed = -boost_duration;
	for (int i = 0; i < 4; i++){
    left_presses[i] = allowed_presses;
    button_down_before[i] = false;
  }
}

bool pushed(int i){
  bool pushed = false;
  bool isDown = pin(i);
  if (!button_down_before[i] && isDown) pushed = true;
  button_down_before[i] = isDown;
  return pushed;
}

bool boostModeOn(){
  if (millis() - last_time_pressed < boost_duration) return true;
  return false;
}

void presses_capped_boost(){
    if (boostModeOn()) return;

    speed = motor_base_speed;
    for (int i = 0; i < 4; i++) {
      if (pushed(i) && left_presses[i] > 0) {
        speed = 255;
		    left_presses[i] -= 1;
        last_time_pressed = millis();
        break;
      }
    }
    motor(speed);
}
