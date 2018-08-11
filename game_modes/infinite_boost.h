void setup_infinite_boost(){
}

void infinite_boost(){
    speed = motor_base_speed;
    for (int i = 0; i < 4; i++) {
      if (pin(i)) {
        speed = 255;
      }
    }
    motor(speed);
}