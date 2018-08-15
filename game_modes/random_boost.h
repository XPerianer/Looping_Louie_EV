//const int boost_time = 3000;

//long left[4];
//long last_time;
long time_frame=500;
long begin_mode = 0;
int mode=59;

void setup_random_boost(){
	last_time = millis();
	left[0] = boost_time;
	left[1] = boost_time;
	left[2] = boost_time;
	left[3] = boost_time;
	randomSeed(analogRead(0));
	mode = random(0,100);
	time_frame = random(800, 1500);
	begin_mode = millis();
}

int mode_to_motor_speed(int mode){ //Range of mode from 0 - 99
	if(mode < 20)
		return 255;
	if(mode < 30)
		return 125;
	if(mode < 40)
		return 90;
	if(mode < 60)
		return 0;
	if(mode < 80)
		return -125;
	return motor_base_speed;
}

void random_boost(){
	if(millis() - begin_mode > time_frame){ //Select new mode and time_frame
		mode = random(0,100);
		time_frame = random(800, 1500);
		begin_mode = millis();
	}
	
    speed = mode_to_motor_speed(mode);
    for (int i = 0; i < 4; i++) {
      if (pin(i) && left[i] > 0) {
        speed = 255;
		left[i] -= millis() - last_time;
      }
    }
	last_time = millis();
    motor(speed);
}

