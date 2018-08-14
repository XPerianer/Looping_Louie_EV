void setup_slow_speedup(){
	speed = motor_base_speed;
}

void slow_speedup(){
	motor(speed);
	delay(500);
	if(speed < 255){
		speed++;
	}
}
