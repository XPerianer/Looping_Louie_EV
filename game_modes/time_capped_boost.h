const int boost_time = 3000;

long left[4];
long last_time;

void setup_time_capped_boost(){
	last_time = millis();
	left[0] = boost_time;
	left[1] = boost_time;
	left[2] = boost_time;
	left[3] = boost_time;
}

void time_capped_boost(){
    speed = motor_base_speed;
    for (int i = 0; i < 4; i++) {
      if (pin(i) && left[i] > 0) {
        speed = 255;
		left[i] -= millis() - last_time;
      }
    }
	last_time = millis();
    motor(speed);
}