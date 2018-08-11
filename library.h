// Hardware Constants - You should not use these in your code - Use the library functions instead

const int buttons[] = {5, 4, 3, 2};
const int powerswitch_pin = 6;

const int motor_pwm = 9;
const int motor_enable_one = 8;
const int motor_enable_two = 7;
const int status_led = 13;

// functions

void motor(int speed) { // From -255 for full backwards to 255 to full forward (clamped otherwise)
  speed = max(min(255, speed), -255);
  if (speed == 0) {
    digitalWrite(motor_pwm, LOW);
    digitalWrite(motor_enable_one, LOW);
    digitalWrite(motor_enable_two, LOW);
  } else if (speed > 0) {
    analogWrite(motor_pwm, speed);
    digitalWrite(motor_enable_one, HIGH);
    digitalWrite(motor_enable_two, LOW);
  } else {// speed < 0
    analogWrite(motor_pwm, -speed);
    digitalWrite(motor_enable_one, LOW);
    digitalWrite(motor_enable_two, HIGH);
  }
}

void stop(){
  motor(0);
}

bool pin(int number) {
  if (digitalRead(buttons[number]) == LOW)
    return true;
  return false;
}

bool powerswitch() {
  if (digitalRead(powerswitch_pin) == LOW)
    return true;
  return false;
}

void in_out_setup(){
   pinMode(powerswitch_pin, INPUT_PULLUP);
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  pinMode(motor_pwm, OUTPUT);
  pinMode(motor_enable_one, OUTPUT);
  pinMode(motor_enable_two, OUTPUT);
  motor(0);

  pinMode(status_led, OUTPUT);
}


