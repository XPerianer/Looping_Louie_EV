#include "library.h"

const int motor_base_speed = 70;

void setup() {
  pinMode(powerswitch_pin, INPUT_PULLUP);
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  pinMode(motor_pwm, OUTPUT);
  pinMode(motor_enable_one, OUTPUT);
  pinMode(motor_enable_two, OUTPUT);
  motor(0);
}

void loop() {
  while (!powerswitch()) {
    delay(100);
    motor(0);
  }
  while (powerswitch()) {
    int speed = motor_base_speed;
    for (int i = 0; i < 4; i++) {
      if (pin(i)) {
        speed = 255;
      }
    }

    motor(speed);
  }
}



